#ifndef QUEUE_H
#define QUEUE_H

typedef struct link q_node;
typedef struct list queue;
node* q_create_node();
queue* q_create_stack();
void q_enqueue();
void q_dequeue();
void q_clear();
int q_front_value();
int q_length();

#endif
