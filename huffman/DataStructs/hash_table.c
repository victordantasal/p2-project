#include "../Util/default.h"

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

void* HashTable_getValue(Hash_Table *ht, int pos);
Element* HashTable_getTable(Hash_Table *ht, int pos);
int HashTable_getSize(Hash_Table *ht);
int HashTable_getFilled(Hash_Table *ht);

void* Element_getValue(Element *e);
Element* Element_getNext(Element *e);

bool HashTable_setValue(Hash_Table *ht, int pos, void *value);
bool HashTable_setTable(Hash_Table *ht, int pos, Element *new_element);
bool HashTable_setSize(Hash_Table *ht, int new_size);
bool HashTable_setFilled(Hash_Table *ht, int new_filled);

Hash_Table* HashTable_create(int size);
bool HashTable_destruct(Hash_Table *ht);
bool HashTable_add(Hash_Table *ht, void *value, int hash);
