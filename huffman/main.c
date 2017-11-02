#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Util/default.h"
#include "huffman.h"

int main(int argc, char* argv[])
{
	//Arguments different 0
	char *command, *path;
	if(argc == 3)
	{
		/*	huffman.exe [COMMAND] [PATH]
		 * 		0			1		2
		 * 	[COMMAND] e uma palavra "compress" ou "decompress".
		 * 	[PATH] e o caminho para o arquivo.
		 */
		command = argv[1];
		path = argv[2];

		if(!isNull( FileReader_new(path) ) )
		{
			if(strcasecmp(command, "compress") == 0)
			{
				if(huffman_compress(path))
					printf("File was compressed with success\n");
				else
					printf("Erro, its not possible compress this file\nSomething wrong? Please report to admins\n");
			}
			else if(strcasecmp(command, "decompress") == 0)
			{
				if(huffman_decompress(path))
					printf("File was decompressed with success\n");
				else
					printf("Erro, its not possible decompress this file\nSomething wrong? Please report to admins\n");
			}
			else
			{
				printf("ERRO, INVALID COMMAND, TRY 'COMPRESS' OR 'DECOMPRESS'\n");
			}
		}
		else
		{
			printf("ERRO, INVALID PATH\n");
		}
	}
	else
	{
		printf("ERRO, INVALID CALL\n");
	}
	return 0;
}
