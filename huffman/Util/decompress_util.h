#ifndef UTIL_DECOMPRESS_UTIL_H_
#define UTIL_DECOMPRESS_UTIL_H_

#include "../DataStructs/binary_tree.h"
#include "../Util/default.h"

bool readHeader(int *trash, Binary_Tree *bt); //muda o valor de bt e trash
Binary_Tree* stringTo_huffmanTree(char *str);
bool writeData_decompressed(FILE *compressed, FILE *decompressed, Binary_Tree *huffmanTree, int trash);

#endif /* UTIL_DECOMPRESS_UTIL_H_ */
