#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct list array_list;
array_list* al_create_list(int size);
int al_insert(array_list *l, int element);
int al_append(array_list *l, int element);
int al_pop(array_list *l);
int al_clear(array_list *l);
void al_move_to_start(array_list *l);
void al_move_to_end(array_list *l);
int al_move_to_position(array_list *l, int p);
int al_previous(array_list *l);
int al_next(array_list *l);
int al_length(array_list *l);
int al_curr_position(array_list *l);
int al_get_value(array_list *l, int pos);
void al_delete_list(array_list *l);

#endif
