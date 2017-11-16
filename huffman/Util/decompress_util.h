#ifndef UTIL_DECOMPRESS_UTIL_H_
#define UTIL_DECOMPRESS_UTIL_H_

#include "../DataStructs/binary_tree.h"
#include "../Util/default.h"

bool readHeader(FILE *compressed, int *trash, int *tree_size,  char **huffmanTree_str); //muda o valor de huffmanTree_str e trash
Binary_Tree* stringTo_huffmanTree(char *str, int *idx, int size);
bool writeData_decompressed(FILE *compressed, FILE *decompressed, Binary_Tree *huffmanTree, int trash, int tree_size);

#endif /* UTIL_DECOMPRESS_UTIL_H_ */
