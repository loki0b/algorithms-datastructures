#include "../include/node.h"
#include <stdlib.h>

typedef struct list {
    node *front;
    node *rear;
    int length;
} queue;

queue* create_queue() {
    queue *q;

    q = (queue*) malloc(sizeof (queue));
    if (q == NULL) {
        return NULL;
    }
    q->front = q->rear = create_node(NULL, 0);
    q->length = 0;

    return q;
}

int enqueue(queue *q, int element) {
    node *n;

    n = create_node(NULL, element);
    if (n == NULL) {
        return -1;
    }
    q->rear->next_node = n;
    q->rear = q->rear->next_node;
    q->length++;

    return 0;
}

int dequeue(queue *q) {
    if (q->length <= 0) {
        return -1;
    }
    int r;
    node *n;

    r = q->front->next_node->element;
    n = q->front->next_node;
    q->front->next_node = q->front->next_node->next_node;
    if (q->front->next_node == NULL) {
        q->rear = q->front;
    }
    q->length--;
    free(n);

    return r;
}

void q_clear(queue *q) {
    node *n;
    
    q->rear = q->front;
    while(q->front->next_node != NULL) {
        n = q->front->next_node;
        q->front->next_node = q->front->next_node->next_node;
        free(n);
    }
    q->length = 0;
}

int front_value(queue *q) {
    return q->front->next_node->element;
}

int q_length(queue *q) {
    return q->length;
}
