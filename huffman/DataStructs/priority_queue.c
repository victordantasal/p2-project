#include "../Util/default.h"

typedef struct _priority_queue Priority_Queue;
typedef struct _node_priority_queue Node;



//----------STRUCTS------------

struct _priority_queue
{
	Node *head;
	int size;
};

struct _node_priority_queue
{
	void *value;
	int priority;
	Node *next;

};

//----------ADT METHODS-------------

//Enfileira um "value" qualquer na fila de prioridade.
void PriorityQueue_enqueue(Priority_Queue *pq, void *value, int priority);

//Desenfileira o primeiro valor da fila e o retorna.
void* PriorityQueue_dequeue(Priority_Queue *pq);

bool PriorityQueue_isEmpty(Priority_Queue *pq);

void PriorityQueue_destruct(Priority_Queue *pq);

Priority_Queue* PriorityQueue_create();

//Cria um nó
Node* Node_new(void *value, int priority);




//-----------ENCAPSULAMENTO-----------

//GETS
Node* PriorityQueue_getHead(Priority_Queue *pq);
int   PriorityQueue_getSize(Priority_Queue *pq);
void* Node_getValue(Node *node);
int   Node_getPriority(Node *node);
Node* Node_getNext(Node *node);


//SETS
int PriorityQueue_setHead(Priority_Queue *pq, Node *new_head);
int PriorityQueue_setSize(Priority_Queue *pq, int new_size);
int Node_setValue(Node *node, void *new_value);
int Node_setPriority(Node *node, int new_priority);
int Node_setNext(Node *current, Node *new_next);


//---------IMPLEMENTATION---------
//ADT IMPLEMENTATION <>

Node* Node_new(void *value, int priority)
{
	Node *new_node = (Node*) malloc(sizeof(Node));
	if (Node_setValue(new_node, value) &&
		Node_setPriority(new_node, priority) &&
		Node_setNext(new_node, NULL))
		return new_node;

	DEBUG printf("ERRO, IS NOT POSSIBLE ALOCATE MEMORY");
	return NULL;
}

Priority_Queue* PriorityQueue_create()
{
	Priority_Queue *new_pq = (Priority_Queue*) malloc(sizeof(Priority_Queue));
	if( PriorityQueue_setHead(new_pq, NULL) &&
		PriorityQueue_setSize(new_pq, 0))
		return new_pq;

	DEBUG printf("ERRO, IS NOT POSSIBLE ALOCATE MEMORY");
	return NULL;
}
void PriorityQueue_destruct(Priority_Queue *pq)
{
	while(!PriorityQueue_isEmpty(pq))
		PriorityQueue_dequeue(pq);

	free(pq);
	pq = NULL;
}

bool PriorityQueue_isEmpty(Priority_Queue *pq)
{
	if( !isNull(pq) )
		return pq->size == 0;
	return true;
}

void PriorityQueue_enqueue(Priority_Queue *pq, void *value, int priority)
{
	Node *new_node = Node_new(value, priority);
	Node *aux;
	if(PriorityQueue_isEmpty(pq) || Node_getPriority(PriorityQueue_getHead(pq)) >= priority)
	{
		Node_setNext(new_node, PriorityQueue_getHead(pq));
		PriorityQueue_setHead(pq, new_node);
	}else{
		aux = PriorityQueue_getHead(pq);

		while(!isNull(Node_getNext(aux)) && Node_getPriority(Node_getNext(aux)) < priority)
			aux = Node_getNext(aux);

		Node_setNext(aux, new_node);
		Node_setNext(new_node, Node_getNext(aux));
	}


	PriorityQueue_setSize(pq, PriorityQueue_getSize(pq) + 1);
}

void* PriorityQueue_dequeue(Priority_Queue *pq)
{
	void *value;
	Node *aux;
	if(!PriorityQueue_isEmpty(pq))
	{
		aux = PriorityQueue_getHead(pq);
		value = Node_getValue(aux);
		PriorityQueue_setHead(pq, Node_getNext(aux));
		free(aux);

		PriorityQueue_setSize(pq, PriorityQueue_getSize(pq) - 1);
		return value;
	}
	return NULL;
}

//ADT IMPLEMENTATION <\>

//GETS IMPLEMENTATION<>
Node* PriorityQueue_getHead(Priority_Queue *pq)
{
	if(isNull(pq))
		return NULL;
	return pq->head;
}

int PriorityQueue_getSize(Priority_Queue *pq)
{
	if(isNull(pq))
		return ERROR;
	return pq->size;
}

void* Node_getValue(Node *node)
{
	if(isNull(node))
		return NULL;
	return node->value;
}

int Node_getPriority(Node *node)
{
	if(isNull(node))
		return ERROR;
	return node->priority;
}

Node* Node_getNext(Node *node)
{
	if(isNull(node))
		return NULL;
	return node->next;
}
//GETS IMPLEMENTATION<\>

//SETS IMPLEMENTATION<>
int PriorityQueue_setHead(Priority_Queue *pq, Node *new_head)
{
	if(isNull(pq))
		return false;
	pq->head = new_head;
	return true;
}

int PriorityQueue_setSize(Priority_Queue *pq, int new_size)
{
	if(isNull(pq))
		return false;
	pq->size = new_size;
	return true;
}

int Node_setValue(Node *node, void *new_value)
{
	if(isNull(node))
		return false;
	node->value = new_value;
	return true;
}

int Node_setPriority(Node *node, int new_priority)
{
	if(isNull(node))
		return false;
	node->priority = new_priority;
	return true;
}

int Node_setNext(Node *current, Node *new_next)
{
	if(isNull(current))
		return false;
	current->next = new_next;
	return true;
}
//SETS IMPLEMENTATION<\>
