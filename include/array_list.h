#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct list array_list;
array_list* create_list(int size);
int insert(array_list *l, int element);
int append(array_list *l, int element);
int pop(array_list *l);
int clear(array_list *l);
void move_to_start(array_list *l);
void move_to_end(array_list *l);
int move_to_position(array_list *l, int p);
int previous(array_list *l);
int next(array_list *l);
int length(array_list *l);
int curr_position(array_list *l);
int get_value(array_list *l, int pos);
void delete_array_list(array_list *l);

#endif
