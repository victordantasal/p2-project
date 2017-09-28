#ifndef HEADERS_DEFAULT_H_
#define HEADERS_DEFAULT_H_

//INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isNull(void *ptr);
#define ERROR -404
#define DEBUG if(DEBUG_STATUS)
bool DEBUG_STATUS = true;


#endif /* HEADERS_DEFAULT_H_ */
