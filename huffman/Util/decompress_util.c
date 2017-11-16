#include "decompress_util.h"

//int idx = 0;

bool readHeader(FILE *compressed, int *trash, int *tree_size,  char **huffmanTree_str)
{
	if(!isNull(compressed))
	{
		rewind(compressed);
		Byte first = fgetc(compressed);
		Byte second = fgetc(compressed);


		*(trash) = first >> 5;
		*(tree_size) = ((first & 31) << 8) | (second);
		*huffmanTree_str = (char*) malloc(sizeof(char) * (*(tree_size) + 1));
		int i;
		for(i = 0; i < *(tree_size); i++)
		{
			(*huffmanTree_str)[i] = fgetc(compressed);
		}

		if(!isNull(*huffmanTree_str))
			return true;
		else
			return false;
	}
	return false;
}

Binary_Tree* stringTo_huffmanTree(char *str, int *idx, int size)
{
	//idx é uma variavel global
	Byte *value;
	//se a string ainda tiver conteúdo
	if(size != *idx)
	{
		//se não for *
		if(str[*idx] != '*')
		{
			//se for \ o próximo é uma folha da arvore
			//se não for, o atual é uma folha.
			if(str[*idx] == '\\')
				*idx = *idx + 1;
			//criar uma folha
			value = (Byte*)malloc(sizeof(Byte));
			*value = (Byte) str[*idx];
			return BinaryTree_new(value, NULL, NULL);
		}else{
			//criar um 'nó interno'
			value = (Byte*) malloc(sizeof(Byte));
			*value = (Byte) str[*idx]; //str[idx] é * nesse caso
			Binary_Tree *new_bt = BinaryTree_new(value,NULL,NULL);

			*idx = *idx + 1;
			BinaryTree_setLeft(new_bt, stringTo_huffmanTree(str,idx, size));
			*idx = *idx + 1;
			BinaryTree_setRight(new_bt, stringTo_huffmanTree(str,idx, size));

			return new_bt;
		}
	}
	printf("null");
	//se a entrada for vazia retorna NULL.
	return NULL;
}

bool writeData_decompressed(FILE *compressed, FILE *decompressed, Binary_Tree *huffmanTree, int trash, int tree_size)
{
	if(!isNull(compressed) && !isNull(decompressed))
	{
		Binary_Tree *aux;
		Byte *value;
		Byte current, next;
		int data_begin = tree_size + 2;
		int current_bit, end_bit;

		rewind(decompressed);
		fseek(compressed, data_begin, SEEK_SET);

		current = fgetc(compressed);
		aux = huffmanTree;
		bool decompressing = true;

		do{
			next = fgetc(compressed);
			end_bit = 0;
			current_bit = 7;

			if(feof(compressed))
			{
				end_bit = trash;
				decompressing = false;
				//será a ultima execução
			}
			while(current_bit >= end_bit)
			{
				if( isBit_i_set(current, current_bit)) //se o bit for 1
				{
					aux = BinaryTree_getRight(aux);
				}else{								//se o bit for 0
					aux = BinaryTree_getLeft(aux);
				}

				if(BinaryTree_isLeaf(aux))
				{
					value = (Byte*) BinaryTree_getValue(aux);
					//printf("Writing: %d",*value);
					fputc(*value, decompressed);
					aux = huffmanTree;
				}
				current_bit--;
			}
			current = next;
		}while(decompressing);
		return true;
	}
	return false;
}
