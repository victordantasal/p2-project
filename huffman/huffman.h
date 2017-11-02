#ifndef HUFFMAN_H_
#define HUFFMAN_H_

#include "./Util/compress_util.h"
#include "./Util/decompress_util.h"

bool huffman_compress(char *file_path);
bool huffman_decompress(char *file_path);


#endif /* HUFFMAN_H_ */
