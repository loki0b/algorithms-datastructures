#include <stdlib.h>

typedef struct node {
  int data;
  struct node* next_node;
} Node;

typedef struct list {
  Node* head;
  Node* curr;
  Node* tail;
  int length;
} List;

Node* create_node(Node* node, int value) {
  Node* n = (Node*) malloc(sizeof(Node));
  n->data = value;
  n->next_node = node;

  return n;
}

List* create_list() {
  List* l = (List*) malloc(sizeof(List));
  l->head = l->curr = l->curr = create_node(NULL, 0);
  l->length = 0;

  return l;
}

void insert(List* l, int value) {
  l->curr->next_node = create_node(l->curr->next_node, value);
  if (l->curr == l->tail) {
    l->tail = l->curr->next_node;
  }
  l->length++;
}

void append(List* l, int value) {
  l->tail = create_node(l->tail->next_node, value);
  l->length++;
}

int pop(List* l) {
  if (l->curr->next_node == NULL) return;
  
  Node* temp = l->curr->next_node;
  int value = l->curr->next_node->data;
  l->curr->next_node = l->curr->next_node->next_node;
  free(temp);
  l->length--;

  return value;
}

void clear(List* l) {
  l->curr = l->tail = l->head;
  Node* temp;
  while (l->curr->next_node != NULL) {
    temp = l->curr->next_node;
    l->curr->next_node = l->curr->next_node->next_node;
    free(temp);
  }
  l->length = 0;
}

void delete_list(List* l) {
  clear(l);
  free(l->head);
  free(l);
}

void move_to_start(List* l) {
  l->curr = l->head;
}
// TODO: check if insert works after next to the tail
void next(List* l) {
  if (l->curr != l->tail) l->curr = l->curr->next_node;
}

void previous(List* l) {
  if (l->curr =! l->head) {
    Node* temp = l-head;
    while (temp->next_node != l->curr) {
      temp = temp->next_node;
    }
    l->curr = temp;
  }
}

int length(List* l) {
  return l->length;
}


int get_value(List* l) {
  if (l->length == 0 || l->curr->next_node == NULL) return;

  return l->curr->next_node->data;
}
