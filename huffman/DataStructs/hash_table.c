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
	if(isNull(ht->table[pos]))
		return NULL;
	return ht->table[pos]->value;
}

Element* HashTable_getTable(Hash_Table *ht, int pos)
{
	if(isNull(ht->table[pos]))
		return NULL;
	return ht->table[pos];
}

int HashTable_getSize(Hash_Table *ht)
{
	if(isNull(ht))
		return ERROR;
	return ht->maxsize;
}
int HashTable_getFilled(Hash_Table *ht)
{
	if(isNull(ht))
		return ERROR;
	return ht->filled;
}

void* Element_getValue(Element *e)
{
	if(isNull(e))
		return NULL;
	return e->value;
}
Element* Element_getNext(Element *e)
{
	if(isNull(e))
		return NULL;
	return e->next;
}

bool HashTable_setValue(Hash_Table *ht, int pos, void *value)
{
	if(isNull(ht->table[pos]))
		return false;
	ht->table[pos]->value = value;
	return true;
}
bool HashTable_setTable(Hash_Table *ht, int pos, Element *new_element)
{
	if(isNull(ht))
		return false;
	ht->table[pos] = new_element;
	return true;
}
bool HashTable_setSize(Hash_Table *ht, int new_size)
{
	if(isNull(ht))
		return false;
	ht->maxsize = new_size;
	return true;
}
bool HashTable_setFilled(Hash_Table *ht, int new_filled)
{
	if(isNull(ht))
		return false;
	ht->filled = new_filled;
	return true;

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
