#include <stdlib.h>

typedef struct node {
  int data;
  struct node* next_node;
} Node;

typedef struct queue {
  Node* front;
  Node* rear;
  int length;
} Queue;

Node* create_node(Node* node, int value) {
  Node* n = (Node*) malloc(sizeof(Node));
  n->data = value;
  n->next_node = node;

  return n;
}

Queue* create_queue() {
  Queue* q = (Queue*) malloc(sizeof(Queue));
  q->front = q->rear = create_node(NULL, 0);
  q->length = 0;

  return q;
}

void enqueue(Queue* q, int value) {
  q->rear->next_node = create_node(NULL, value);
  q->rear = q->rear->next_node;
  q->length++;
}

int dequeue(Queue* q) {
  if (q->length > 0) {
    int value = q->front->next_node->data;
    Node* temp = q->front->next_node;
    q->front->next_node = q->front->next_node->next_node;
    if (q->front->next_node == NULL) {
      q->rear = q->front;
    }
    free(temp);
    q->length--;

    return value;
  }
}

void clear(Queue* q) {
  if (q->length > 0) {
    Node* temp;
    while (q->front->next_node != NULL) {
      temp = q->front->next_node;
      q->front->next_node = q->front->next_node->next_node;
      free(temp);
    }
    q->length = 0;
  }
}

void delete_queue(Queue* q) {
  clear(q);
  free(q->front);
  free(q);
}

int front_value(Queue* q) {
  if (q->length > 0) return q->front->next_node->data;
}

int length(Queue* q) {
  return q->length;
}
