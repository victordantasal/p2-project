#include "compress_util.h"

int* get_frequency(FILE *file_reader)
{
	//TODO method get frequency ALTERADO
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
