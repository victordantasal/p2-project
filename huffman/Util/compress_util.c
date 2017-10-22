#include "compress_util.h"

int* get_frequency(FILE *file_reader)
{
	int *frequency = (int*) malloc(sizeof(int)*BSIZE);
	Byte aux;

	//ZERANDO ARRAY para iniciar contagem
	memset(frequency, 0, BSIZE);

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

Binary_Tree* get_huffmanTree(int *frequency)
{
	Binary_Tree *bt;
	Priority_Queue *pq = PriorityQueue_create();
	Byte *value;
	int i, sum;

	// Se a frequencia existir entao cria-se uma arvore (com byte) e coloca ela numa fila de prioridade (na posicao 'i' do array)
	for(i = 0; i < BSIZE; i++)
	{
		if(frequency[i] > 0)
		{
			value = (Byte*)malloc(sizeof(Byte));
			*value = i;
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
		bt_aux_right = (Binary_Tree*)PriorityQueue_dequeue(pq);
		sum += Node_getPriority(PriorityQueue_getHead(pq));
		bt_aux_left = (Binary_Tree*)PriorityQueue_dequeue(pq);
		value = (Byte*)malloc(sizeof(Byte));
		*value = '*';
		bt = BinaryTree_new(value, bt_aux_left, bt_aux_right);

		PriorityQueue_enqueue(pq, bt, sum);
	}

	return (Binary_Tree*)PriorityQueue_dequeue(pq);
}

void go_through_tree(Binary_Tree *huffman_tree,Hash_Table *ht,char *new_code)
{
	char aux_left[8], aux_right[8];//s�o strings tempor�rias que ficar�o nos auxiliando a salvar os caminhos durante a recurs�o

	if(is_Leaf(huffman_tree))
	{
		HashTable_add(ht, new_code, (int) BinaryTree_getValue(huffman_tree));
		return;
	}
	else
	{
		strcpy(aux_left,new_code);
		strcpy(aux_right,new_code);

		if(!isNull(BinaryTree_getLeft(huffman_tree)))
			go_through_tree(BinaryTree_getLeft(huffman_tree), ht, strcat(aux_left,"0"));
		if(!isNull(BinaryTree_getRight(huffman_tree)))
			go_through_tree(BinaryTree_getRight(huffman_tree), ht, strcat(aux_right,"1"));
	}
}

Hash_Table* get_dictionary(Binary_Tree *huffman_tree)
{
	Hash_Table *ht = HashTable_create(BSIZE);
	char new_code[8];//essa string serve para salvar o novo c�digo de cada caractere
	strcpy(new_code,"");//deixando a string vazia

	go_through_tree(huffman_tree,ht,new_code);

	return ht;
}

char* getTree_preOrder(Binary_Tree *bt)
{
	char *str = (char*) malloc(sizeof(char));

	if(isNull(bt))
	{
		str[0] = '\0';
	}else{
		char value[2];
		value[0] = *((Byte*) BinaryTree_getValue(bt) );
		value[1] = '\0';

		strcpy(str, value);

		strcat(str, getTree_preOrder(BinaryTree_getLeft(bt)));
		strcat(str, getTree_preOrder(BinaryTree_getRight(bt)));
	}
	return str;
}

bool writeheader_huffmanTree(FILE *file_writer, Binary_Tree *huffman_tree)
{
	if(!isNull(file_writer))
	{
		Byte first, second;
		char *preOrder_tree = getTree_preOrder(huffman_tree);
		int tree_size = strlen(preOrder_tree);

		first  =  31 & (tree_size>>8);
		second = 255 &  tree_size;

		rewind(file_writer);

		fputc(first, file_writer);
		fputc(second, file_writer);
		fputs(preOrder_tree, file_writer);
		return true;
	}

	printf("ERROR INVALID FILE");
	return false;
}

bool writeheader_trash(FILE *file_writer, FILE *file_reader, int trash)
{
	if(!isNull(file_writer))
	{
		Byte byte;

		if(!isNull(file_reader))
		{
			rewind(file_reader);
			byte = fgetc(file_reader);
		}else{
			printf("ERROR INVALID FILE");
			return false;
		}

		byte = byte | (224 & trash);

		rewind(file_writer);

		fputc(byte, file_writer);
		return true;
	}

	printf("ERROR INVALID FILE");
	return false;
}

bool writeData_compressed(FILE *original, FILE *compressed, int *trash) //muda o valor de trash
{
	//TODO method write data, changes trash's value too
	return true;
}
