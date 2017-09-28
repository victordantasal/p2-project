#include <stdlib.h>
#include <stdbool.h>

#define ERROR -404;
#define DEBUG if(DEBUG_STATUS)

typedef struct _priority_queue Priority_Queue;
typedef struct _node_priority_queue Node;
bool DEBUG_STATUS = true;

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
void Priority_Queue_enqueue(Priority_Queue *pq, void *value);

//Desenfileira o primeiro valor da fila e o retorna.
void* Priority_Queue_dequeue(Priority_Queue *pq);

//Cria um nó
Node* Node_new(void *value, int priority);


//-----------ENCAPSULAMENTO-----------

//GETS
Node* Priority_Queue_get_head(Priority_Queue *pq);
int Priority_Queue_get_size(Priority_Queue *pq);
void* Node_get_value(Node *node);
int Node_get_priority(Node *node);
Node* Node_get_next(Node *node);


//SETS
int Priority_Queue_set_head(Priority_Queue *pq, Node *new_head);
int Priority_Queue_set_size(Priority_Queue *pq, int new_size);
int Node_set_value(Node *node, void *new_value);
int Node_set_priority(Node *node, int new_priority);
int Node_set_next(Node *current, Node *new_next);


//---------IMPLEMENTATION---------
//ADT IMPLEMENTATION <>
bool is_null(void *ptr)
{
	return ptr == NULL;
}

Node* Node_new(void *value, int priority)
{
	Node *new_node = (Node*) malloc(sizeof(Node));
	if (Node_set_value(new_node, value) &&
		Node_set_priority(new_node, priority) &&
		Node_set_next(new_node, NULL))
		return new_node;

	DEBUG printf("ERRO, IS NOT POSSIBLE ALOCATE MEMORY");
	return NULL;
}

bool Priority_Queue_is_empty(Priority_Queue *pq)
{
	if( !is_null(pq) )
		return pq->size == 0;
	return true;
}

void Priority_Queue_enqueue(Priority_Queue *pq, void *value, int priority)
{
	Node *new_node = Node_new(value, priority);
	Node *aux;
	if(Priority_Queue_is_empty(pq) || Node_get_priority(Priority_Queue_get_head(pq)) >= priority)
	{
		Node_set_next(new_node, Priority_Queue_get_head(pq));
		Priority_Queue_set_head(pq, new_node);
	}else{
		aux = Priority_Queue_get_head(pq);

		while(!is_null(Node_get_next(aux)) && Node_get_priority(Node_get_next(aux)) < priority)
			aux = Node_get_next(aux);

		Node_set_next(aux, new_node);
		Node_set_next(new_node, Node_get_next(aux));
	}


	Priority_Queue_set_size(pq, Priority_Queue_get_size(pq) + 1);
}

void* Priority_Queue_dequeue(Priority_Queue *pq)
{
	void *value;
	Node *aux;
	if(!Priority_Queue_is_empty(pq))
	{
		aux = Priority_Queue_get_head(pq);
		value = Node_get_value(aux);
		Priority_Queue_set_head(pq, Node_get_next(aux));
		free(aux);

		Priority_Queue_set_size(pq, Priority_Queue_get_size(pq) - 1);
		return value;
	}
	return NULL;
}

//ADT IMPLEMENTATION <\>

//GETS IMPLEMENTATION<>
Node* Priority_Queue_get_head(Priority_Queue *pq)
{
	if(is_null(pq))
		return NULL;
	return pq->head;
}

int Priority_Queue_get_size(Priority_Queue *pq)
{
	if(is_null(pq))
		return ERROR;
	return pq->size;
}

void* Node_get_value(Node *node)
{
	if(is_null(node))
		return NULL;
	return node->value;
}

int Node_get_priority(Node *node)
{
	if(is_null(node))
		return ERROR;
	return node->priority;
}

Node* Node_get_next(Node *node)
{
	if(is_null(node))
		return NULL;
	return node->next;
}
//GETS IMPLEMENTATION<\>

//SETS IMPLEMENTATION<>
int Priority_Queue_set_head(Priority_Queue *pq, Node *new_head)
{
	if(is_null(pq))
		return false;
	pq->head = new_head;
	return true;
}

int Priority_Queue_set_size(Priority_Queue *pq, int new_size)
{
	if(is_null(pq))
		return false;
	pq->size = new_size;
	return true;
}

int Node_set_value(Node *node, void *new_value)
{
	if(is_null(node))
		return false;
	node->value = new_value;
	return true;
}

int Node_set_priority(Node *node, int new_priority)
{
	if(is_null(node))
		return false;
	node->priority = new_priority;
	return true;
}

int Node_set_next(Node *current, Node *new_next)
{
	if(is_null(current))
		return false;
	current->next = new_next;
	return true;
}
//SETS IMPLEMENTATION<\>
