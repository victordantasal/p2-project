#include "compress_util.h"

int* get_frequency(FILE *file_reader)
{
	int i, *frequency = (int*) malloc(sizeof(int)*BSIZE);
	Byte aux;

	if(!isNull(file_reader))
	{
		//ZERANDO ARRAY para iniciar contagem
		for(i = 0; i < BSIZE; i++)
			frequency[i] = 0;

		//resetando o ponteiro de leitura para o inicio do arquivo.
		rewind(file_reader);

		//iniciando contagem das frequencias no arquivo
		//at� que se leia EOF
		do{
			aux = fgetc(file_reader);

			if(feof(file_reader))
				break;

			frequency[aux]++;
		}while(1);
	}
}

Binary_Tree* get_huffmanTree(int *frequency)
{
	Binary_Tree *bt;
	Priority_Queue *pq = PriorityQueue_create();
	Byte *value;
	int i, sum;

	// Se a frequencia existir entao cria-se uma arvore (com byte) e coloca ela numa fila de prioridade (na posicao 'i' do array)
	for(i=0; i<BSIZE; i++)
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
	char aux_left[9], aux_right[9];//s�o strings tempor�rias que ficar�o nos auxiliando a salvar os caminhos durante a recurs�o

	if(isNull(huffman_tree->left) && isNull(huffman_tree->right))
	{
		HashTable_add(ht,new_code,huffman_tree->value);
		return;
	}
	else
	{
		strcpy(aux_left,new_code);
		strcpy(aux_right,new_code);

		if(!isNull(huffman_tree->left))
			go_through_tree(huffman_tree->left,ht,strcat(aux_left,"0"));
		if(!isNull(huffman_tree->right))
			go_through_tree(huffman_tree->right,ht,strcat(aux_right,"1"));
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

bool writeheader_huffmanTree(FILE *file_writer, Binary_Tree *huffman_tree)
{
	//TODO method write header HuffmanTree
}

bool writeheader_trash(FILE *file_writer, int trash)
{
	//TODO method write header trash
}

bool writeData_compressed(FILE *original, FILE *compressed, int *trash) //muda o valor de trash
{
	//TODO method write data, changes trash's value too
}
