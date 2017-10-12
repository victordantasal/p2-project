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
		//até que se leia EOF
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
	//TODO method get huffmanTree
}

Hash_Table* get_dictionary(Binary_Tree *huffman_tree)
{
	//TODO method get dictionary
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
