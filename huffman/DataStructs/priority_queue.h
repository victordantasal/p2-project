#ifndef DATASTRUCTS_PRIORITY_QUEUE_H_
#define DATASTRUCTS_PRIORITY_QUEUE_H_

#include "../Util/default.h"

typedef struct _priority_queue Priority_Queue;
typedef struct _node_priority_queue Node;

struct _priority_queue;
struct _node_priority_queue;

void PriorityQueue_enqueue(Priority_Queue *pq, void *value, long int priority);
void* PriorityQueue_dequeue(Priority_Queue *pq);
bool PriorityQueue_isEmpty(Priority_Queue *pq);
void PriorityQueue_destruct(Priority_Queue *pq);
Priority_Queue* PriorityQueue_create();
Node* Node_new(void *value, long int priority);


Node* PriorityQueue_getHead(Priority_Queue *pq);
int   PriorityQueue_getSize(Priority_Queue *pq);
void* Node_getValue(Node *node);
int   Node_getPriority(Node *node);
Node* Node_getNext(Node *node);


bool PriorityQueue_setHead(Priority_Queue *pq, Node *new_head);
bool PriorityQueue_setSize(Priority_Queue *pq, int new_size);
bool Node_setValue(Node *node, void *new_value);
bool Node_setPriority(Node *node, int new_priority);
bool Node_setNext(Node *current, Node *new_next);

#endif /* DATASTRUCTS_PRIORITY_QUEUE_H_ */
