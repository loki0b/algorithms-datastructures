#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct node Node;
typedef struct queue Queue;
Node* create_node(Node* node, int value);
Queue* create_queue();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
void clear(Queue* q);
void delete_queue(Queue* q);
int front_value(Queue* q);
int length(Queue* q);

#endif
