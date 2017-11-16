#include "default.h"

bool isNull(void *ptr)
{
	return ptr == NULL;
}

FILE* FileReader_new(char *path)
{
	FILE* file = fopen(path, "rb");
	if(!isNull(file))
		return file;

	DEBUG printf("CANNOT OPEN THIS FILE. PATH: \"%s\"\n",path);
	return NULL;
}

FILE* FileWriter_new(char *path)
{
	FILE* file = fopen(path, "wb");
	if(!isNull(file))
		return file;

	DEBUG printf("CANNOT OPEN THIS FILE. PATH: \"%s\"\n",path);
	return NULL;
}

bool isBit_i_set(Byte c, int i)
{
	return (c & (1 << i));
}
