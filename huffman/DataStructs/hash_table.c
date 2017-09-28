#include "hash_table.h"

typedef struct _hash_table Hash_Table;
typedef struct _element Element;

struct _hash_table
{
	Element *table;
	int maxsize;
	int filled;
};

struct _element
{
	void *value;
	Element *next;
};

void* HashTable_getValue(Hash_Table *ht, int pos)
{
	//TODO method getValue
}

Element* HashTable_getTable(Hash_Table *ht, int pos)
{
	//TODO method getTable
}

int HashTable_getSize(Hash_Table *ht)
{
	//TODO method getSize
}
int HashTable_getFilled(Hash_Table *ht)
{
	//TODO method getFilled
}

void* Element_getValue(Element *e)
{
	//TODO method getValue
}
Element* Element_getNext(Element *e)
{
	//TODO method getNext
}

bool HashTable_setValue(Hash_Table *ht, int pos, void *value)
{
	//TODO method setValue
}
bool HashTable_setTable(Hash_Table *ht, int pos, Element *new_element)
{
	//TODO method setTable
}
bool HashTable_setSize(Hash_Table *ht, int new_size)
{
	//TODO method setValue
}
bool HashTable_setFilled(Hash_Table *ht, int new_filled)
{
	//TODO method setFilled
}

Hash_Table* HashTable_create(int size)
{
	//TODO method create a hash table with size SIZE
}
bool HashTable_destruct(Hash_Table *ht)
{
	//TODO method destruct
}
bool HashTable_add(Hash_Table *ht, void *value, int hash)
{
	//TODO method add on hash
}
