#include "decompress_util.h"

bool readHeader(int *trash, char *huffmanTree_str)
{
	return false;
}

Binary_Tree* stringTo_huffmanTree(char *str)//por enquanto s� conseguir fazer usando vari�vel global (idx),obs: n�o declarei em nenhum lugar o idx,por isso est� dando erro
{
	if(str[idx] != '*')
	{
		if(str[idx] == '\\')
		{
			idx++;
			Binary_Tree *new_bt = BinaryTree_new(str[idx],NULL,NULL);
			return new_bt;
		}
		else
		{
			Binary_Tree *new_bt = BinaryTree_new(str[idx],NULL,NULL);
			return new_bt;
		}
	}
	else
	{
		Binary_Tree *new_bt = BinaryTree_new(str[idx],NULL,NULL);

		idx++;
		new_bt->left = stringTo_huffmanTree(str);
		idx++;
		new_bt->right = stringTo_huffmanTree(str);
	}
}

bool writeData_decompressed(FILE *compressed, FILE *decompressed, Binary_Tree *huffmanTree, int trash)
{
	return true;
}
