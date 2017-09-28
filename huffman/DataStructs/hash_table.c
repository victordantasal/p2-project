#include "../Util/default.h"

typedef struct _hash_table Hash_Table;
typedef struct _element Element;

struct _hash_table
{
	Element *table;
	int size;
};

struct _element
{
	void *value;
	Element *next;
};

