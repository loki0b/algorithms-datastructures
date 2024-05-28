#ifndef QUEUE_H
#define QUEUE_H

typedef struct list queue;
queue* create_queue();
int enqueue(queue *q, int element);
int dequeue(queue *q);
void q_clear(queue *q);
int front_value(queue *q);
int q_length(queue *q);

#endif
