#include "default.h"

typedef unsigned char Byte;

bool isNull(void *ptr)
{
	return ptr == NULL;
}

FILE* FileReader_new(char *path)
{
	FILE* file = fopen(path, "rb");
	if(!isNull(file))
		return file;

	DEBUG printf("CANNOT OPEN THIS FILE.\n Path: %s",path);
	return NULL;
}

FILE* FileWriter_new(char *path)
{
	FILE* file = fopen(path, "wb");
	if(!isNull(file))
		return file;

	DEBUG printf("CANNOT OPEN THIS FILE.\n Path: %s",path);
	return NULL;
}
