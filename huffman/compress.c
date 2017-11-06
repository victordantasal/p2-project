#include "./Util/compress_util.h"
#include "./huffman.h"

void print(void *value)
{
	printf("%c",*((Byte*) value) );
}

/*
 * @params recebe um caminho valido de arquivo
 * @output gera um arquivo compactado como saida
 * @returns TRUE se realizar todos os passo com sucesso
 * 			    FALSE se houver algum erro.
 */
bool huffman_compress(char *file_path)
{
	bool response = false;
	char compressed_file_path[500];
	int trash_size;

	//criar url para arquivo comprimido
	strcpy(compressed_file_path, file_path);
	strcat(compressed_file_path, ".huff");

	FILE *original_fileReader = FileReader_new(file_path);
	FILE *compressed_fileWriter = FileWriter_new(compressed_file_path);
	FILE *compressed_fileReader = FileReader_new(compressed_file_path);

	int *frequency = get_frequency(original_fileReader);
	DEBUG printf("GETTING HUFFMAN TREE");
	Binary_Tree *huffman_tree = get_huffmanTree(frequency);
	BinaryTree_printPreOrder(huffman_tree, print);
	Hash_Table *dictionary = get_dictionary(huffman_tree);

	if( writeheader_huffmanTree(compressed_fileWriter, huffman_tree) )
	if( writeData_compressed(original_fileReader, compressed_fileWriter, dictionary, &trash_size) )
	  if( writeheader_trash(compressed_fileWriter, compressed_fileReader, trash_size) )
		response = true;

	//liberar memoria alocada
	fclose(original_fileReader);
	fclose(compressed_fileWriter);
	fclose(compressed_fileReader);
	free(frequency);
	BinaryTree_destruct(huffman_tree);
	HashTable_destruct(dictionary);

	return response;
}
