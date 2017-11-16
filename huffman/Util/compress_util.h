#ifndef UTIL_COMPRESS_UTIL_H_
#define UTIL_COMPRESS_UTIL_H_

#include "../DataStructs/binary_tree.h"
#include "../DataStructs/hash_table.h"
#include "../DataStructs/priority_queue.h"
#include "../Util/default.h"


int* get_frequency(FILE *file_reader);
Binary_Tree* get_huffmanTree(int *frequency);
Hash_Table* get_dictionary(Binary_Tree *huffman_tree);
bool writeheader_huffmanTree(FILE *file_writer, Binary_Tree *huffman_tree);
bool writeheader_trash(FILE *file_writer, FILE *file_reader, int trash);
bool writeData_compressed(FILE *original, FILE *compressed, Hash_Table *dictionary, int *trash); //muda o valor de trash
char* getTree_preOrder(Binary_Tree *bt);


#endif /* UTIL_COMPRESS_UTIL_H_ */
