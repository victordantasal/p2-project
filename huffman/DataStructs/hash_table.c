#include "hash_table.h"

typedef struct _hash_table Hash_Table;
typedef struct _element Element;

struct _hash_table
{
	Element **table;
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

bool Element_setValue(Element *e,void *value)
{
	if(isNull(e))
		return false;
	e->value = value;
	return true;
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
	int i;
	Hash_Table *new_ht = (Hash_Table*) malloc(sizeof(Hash_Table));
	if(HashTable_setSize(new_ht,size) && HashTable_setFilled(new_ht,0))
		new_ht->table = malloc(HashTable_getSize(new_ht) * sizeof(Element));
	    for(i = 0; i < HashTable_getSize(new_ht); i++) new_ht->table[i] = NULL;
	    return new_ht;

	DEBUG printf("ERROR, IT'S NOT POSSIBLE TO ALOCATE MEMORY");
	return NULL;
}
bool HashTable_destruct(Hash_Table *ht)
{
	if(isNull(ht))
		return false;

	int i;
	for(i = 0; i < HashTable_getSize(ht); i++)
	{
        if(HashTable_getTable(ht,i) != NULL)
        	free(ht->table[i]);
	}
	free(ht);
	return true;
}
bool HashTable_add(Hash_Table *ht, void *value, int pos)
{
	int h = pos % BSIZE;
	char aux[8];
	strcpy(aux,value);

	if(HashTable_getTable(ht,h) == NULL)
	{
		Element *new_element = (Element*) malloc(sizeof(Element));
		if(Element_setValue(new_element,aux) && HashTable_setTable(ht,h,new_element))
			HashTable_getFilled(ht)++;
			return true;
	}

	return false;
}
