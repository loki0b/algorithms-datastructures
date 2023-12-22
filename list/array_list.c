#include <stdlib.h>

typedef struct list {
  int max_size;
  int list_size;
  int curr;
  int* list_array;
} List;

List* create_list(int size) {
  List* l = (List*) malloc(sizeof(List));
  l->max_size = size;
  l->list_size = l->curr = 0;
  l->list_array = malloc(size * sizeof(int));

  return l;
}

void insert(List* l, int value) {
  if (l->list_size >= l->max_size) return;

  int i = l->list_size;
  while (i > l->curr) {
    l->list_array[i] = l->list_array[i - 1];
    i++;
  }
  l->list_array[l->curr] = value;
  l->list_size++;
}

void append(List* l, int value) {
  if (l->list_size >= l->max_size) return;

  l->list_array[l->list_size] = value;
  l->list_size++;
}

int pop(List* l) {
  if (l->curr < 0 || l->curr > l->list_size) return -1;
 
  int value = l->list_array[l->curr];
  int i = l->curr;
  while (i < l->list_size - 1) {
    l->list_array[i] = l->list_array[i + 1];
    i++;
  }
  l->list_size--;

  return value;
}

void clear(List* l) {
  l->list_size = l->curr = 0;
}

void delete_list(List* l) {
  free(l->list_array);
  free(l);
}

void move_to_start(List* l) {
  l->curr = 0;
}

void move_to_end(List* l) {
  l->curr = l->list_size;
}

void move_to_position(List* l, int position) {
  if (position < 0 || position > l->list_size) return;

  l->curr = position;
}

void next(List* l) {
  if (l->curr < l->list_size) {
    l->curr++;
  }
}

void previous(List* l) {
  if (l->curr > 0) {
    l->curr--;
  }
}

int length(List* l) {
  return l->list_size;
}

int get_value(List* l) {
  return l->list_array[l->curr];
}
