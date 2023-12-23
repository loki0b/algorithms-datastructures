#include <stdlib.h>

typedef struct node {
  int data;
  struct node* next_node;
} Node;

typedef struct stack {
  Node* top;
  int length;  
} Stack;

Node* create_node(Node* node, int value) {
  Node* n = (Node*) malloc(sizeof(Node));
  n->data = value;
  n->next_node = node;

  return n;
}

Stack* create_stack() {
  Stack* s = (Stack*) malloc(sizeof(Stack));
  s->top = NULL;
  s->length = 0;

  return s;
}

void push(Stack* s, int value) {
  s->top = create_node(s->top, value);
  s->length++;
}

int pop(Stack* s) {
  if (s->top != NULL) {
    int value = s->top->data;
    Node* temp = s->top;
    s->top = s->top->next_node;
    s->length--;
    free(temp);

    return value;
  }
}

void clear(Stack* s) {
  if (s->length > 0 && s->top != NULL) {
    Node* temp = s->top;
    while (temp != NULL) {
      s->top->next_node;
      free(temp);
      temp = s->top;
    }
    s->length = 0;
  }
}

void delete_stack(Stack* s) {
  clear(s);
  free(s);
}

int top_value(Stack* s) {
  if (s->top != NULL) return s->top->data;
}

int length(Stack* s) {
  return s->length;
}
