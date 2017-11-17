#include "compress_util.h"

long int* get_frequency(FILE *file_reader)
{
	long int *frequency = (long int*) malloc(sizeof(long int)*BSIZE);
	Byte aux;

	//ZERANDO ARRAY para iniciar contagem
	memset(frequency, 0, sizeof(int)*BSIZE );

	if(!isNull(file_reader))
	{
		//resetando o ponteiro de leitura para o inicio do arquivo.
		rewind(file_reader);

		//iniciando contagem das frequencias no arquivo
		//ate que se leia EOF
		do{
			aux = fgetc(file_reader);

			if(feof(file_reader))
				break;

			frequency[aux]++;
		}while(1);
	}else
		printf("ERROR INVALID FILE");
	return frequency;
}

void printQueue(Priority_Queue *pq)
{
	Node *aux = PriorityQueue_getHead(pq);
	while(!isNull(aux))
	{
		printf("\tP:%d V:%c,", Node_getPriority(aux), *((Byte*)BinaryTree_getValue(Node_getValue(aux))));
		aux = Node_getNext(aux);
	}
	printf("  END\n\n");
}

Binary_Tree* get_huffmanTree(long int *frequency, int *tree_size)
{
	Binary_Tree *bt;
	Priority_Queue *pq = PriorityQueue_create();
	Byte *value;
	int i;
	long int sum;

	// Se a frequencia existir entao cria-se uma arvore (com byte) e coloca ela numa fila de prioridade (na posicao 'i' do array)
	for(i = 0; i < BSIZE; i++)
	{
		if(frequency[i] > 0)
		{
			value = (Byte*)malloc(sizeof(Byte));
			*value = i;
			if(i == 42 || i == 92)
				*tree_size += 1;
			*tree_size += 1;
			bt = BinaryTree_new(value, NULL, NULL);
			PriorityQueue_enqueue(pq, bt, frequency[i]);
		}
	}
	// Dando merge ate que a fila tenha tamanho 1
	Binary_Tree *bt_aux_right, *bt_aux_left;
	while(PriorityQueue_getSize(pq) > 1)
	{
		sum = 0;
		sum += Node_getPriority(PriorityQueue_getHead(pq));
		bt_aux_left = (Binary_Tree*)PriorityQueue_dequeue(pq);
		sum += Node_getPriority(PriorityQueue_getHead(pq));
		bt_aux_right = (Binary_Tree*)PriorityQueue_dequeue(pq);
		value = (Byte*)malloc(sizeof(Byte));
		*value = 42;
		*tree_size += 1;
		bt = BinaryTree_new(value, bt_aux_left, bt_aux_right);

		PriorityQueue_enqueue(pq, bt, sum);
	}
	DEBUG printf("GET DICTIONARY END\n");
	return (Binary_Tree*)PriorityQueue_dequeue(pq);
}

void go_through_tree(Binary_Tree *huffman_tree,Hash_Table *ht,char *new_code)
{
	char *left, *right;
	left = (char*) malloc(sizeof(char)*10);
	right = (char*) malloc(sizeof(char)*10);

	if(BinaryTree_isLeaf(huffman_tree))
	{
		HashTable_add(ht, new_code, (int) *((Byte*) BinaryTree_getValue(huffman_tree)));
		return;
	}
	else
	{
		strcpy(left,new_code);
		strcpy(right,new_code);

		if(!isNull(BinaryTree_getLeft(huffman_tree)))
			go_through_tree(BinaryTree_getLeft(huffman_tree), ht, strcat(left,"0"));
		if(!isNull(BinaryTree_getRight(huffman_tree)))
			go_through_tree(BinaryTree_getRight(huffman_tree), ht, strcat(right,"1"));
	}
}

Hash_Table* get_dictionary(Binary_Tree *huffman_tree)
{
	DEBUG printf("GET DICTIONARY BEGIN\n");
	Hash_Table *ht = HashTable_create(BSIZE);
	char new_code[8];//essa string serve para salvar o novo codigo de cada caractere
	strcpy(new_code,"");//deixando a string vazia

	go_through_tree(huffman_tree,ht,new_code);
	DEBUG printf("GET DICTIONARY END\n");
	return ht;
}

void getTree_preOrder(Binary_Tree *bt, char *str, int *index)
{
	Byte *value;
	if(!isNull(bt))
	{
		value = (Byte*) BinaryTree_getValue(bt);
		if(BinaryTree_isLeaf(bt) && (*value == 92 || *value == 42))
		{
			str[*index] = 92;
			*index += 1;
		}
		str[*index] = (Byte) *value;
		*index += 1;
		if(!BinaryTree_isLeaf(bt))
		{
			getTree_preOrder(BinaryTree_getLeft(bt), str, index);
			getTree_preOrder(BinaryTree_getRight(bt), str, index);
		}
	}else{
		printf("\nnull\n");
	}
}

bool writeheader_huffmanTree(FILE *file_writer, Binary_Tree *huffman_tree, int tree_size)
{
	DEBUG printf("WriteHeader BEGIN\n");
	if(!isNull(file_writer))
	{
		rewind(file_writer);
		Byte first = 0, second = 0;
		char *preOrder_tree = (char*) malloc(sizeof(char)*tree_size);
		memset(preOrder_tree, 0, sizeof(char)*tree_size);
		int index = 0;
		getTree_preOrder(huffman_tree, preOrder_tree, &index);
		first  =  31 & (tree_size>>8);
		second = 255 &  tree_size;

		fputc(first, file_writer);
		fputc(second, file_writer);
		int i;
		for (i = 0; i < tree_size; i++)
		{
			fputc((Byte) preOrder_tree[i], file_writer);
		}
		free(preOrder_tree);
		return true;
	}

	printf("ERROR INVALID FILE");
	return false;
}

bool writeheader_trash(FILE *file_reader, FILE *file_writer, int trash)
{
	DEBUG printf("\n\nWriteTrash BEGIN\n");
	if(!isNull(file_reader) && !isNull(file_writer))
	{
		Byte byte;
		rewind(file_reader);
		byte = fgetc(file_reader);
		byte |= (224 & trash << 5);

		rewind(file_writer);
		fputc(byte, file_writer);
		DEBUG printf("WriteTrash END\n");
		return true;
	}

	printf("ERROR INVALID FILE");
	return false;
}

bool writeData_compressed(FILE *original, FILE *compressed, Hash_Table *dictionary, int *trash) //muda o valor de trash
{
	DEBUG printf("\n\nWriteDATA BEGIN\n");
	//TODO method write data, changes trash's value too
	Byte byte, byte_compressed;
	bool last;
	char *code;
	int current_bit, end_bit;

	if(!isNull(original) && !isNull(compressed))
	{
		rewind(original);
		code = (char*)malloc(sizeof(char)*2);
		code[0] = '\0';
		last = false;

		while(!last)
		{
			byte_compressed = 0;
			current_bit = 7;
			end_bit = 0;
			while( current_bit >= end_bit)
			{
				if(code[0] == '\0')
				{
					byte = fgetc(original);

					if(feof(original))
					{
						last = true;
						break;
					}

					code = (char*) HashTable_getValue(dictionary, byte);
				}

				if(code[0] == '1')
					byte_compressed = bit_set(byte_compressed, current_bit);

				code++;
				current_bit--;
			}
			fputc(byte_compressed, compressed);
		}
		*trash = current_bit + 1;
	}
	DEBUG printf("WriteDATA END\n");
	return true;
}
