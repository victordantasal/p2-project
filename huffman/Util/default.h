#ifndef HEADERS_DEFAULT_H_
#define HEADERS_DEFAULT_H_

//INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef unsigned char Byte;

bool isNull(void *ptr);
FILE* FileReader_new(char *path);
FILE* FileWriter_new(char *path);
bool isBit_i_set(Byte c, int i);
Byte bit_set(Byte c, int i);

#define ERROR -404
#define DEBUG if(1) //  1 para mostrar saída DEBUG, 0 para não mostrar.
#define BSIZE 256


#endif /* HEADERS_DEFAULT_H_ */
