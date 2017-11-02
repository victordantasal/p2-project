#include "./Util/decompress_util.h"
#include "huffman.h"
/*
 * @params recebe um caminho valido de arquivo.huff
 * @output gera um arquivo descompactado como saida
 * @returns TRUE se realizar todos os passo com sucesso
 * 			    FALSE se houver algum erro.
 */
bool huffman_decompress(char *file_path)
{
	bool response = false;
	int trash_size;
	char decompressed_file_path[500];
	char huffmanTree_str[500];

	strcpy(decompressed_file_path, file_path);
	decompressed_file_path[ strlen(decompressed_file_path) - 6 ] = '\0';

	FILE *compressed_fileReader = FileReader_new(file_path);
	FILE *decompressed_fileWriter = FileWriter_new(decompressed_file_path);

	Binary_Tree *huffman_tree = NULL;

	if( readHeader(&trash_size, huffmanTree_str) )
	{
		huffman_tree = stringTo_huffmanTree(huffmanTree_str);
		if(!isNull(huffman_tree))
		  if( writeData_decompressed(compressed_fileReader, decompressed_fileWriter, huffman_tree, trash_size) )
			response = true;
	}

	fclose(compressed_fileReader);
	fclose(decompressed_fileWriter);
	BinaryTree_destruct(huffman_tree);

	return response;
}
