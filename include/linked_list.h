#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct link ll_node;
typedef struct list linked_list;
node* ll_create_node(node *next_node, int element);
linked_list* ll_create_list();
int ll_insert(linked_list *l, int element);
int ll_append(linked_list *l, int element);
int ll_pop(linked_list *l);
void ll_clear(linked_list *l);
void ll_move_to_start(linked_list *l);
void ll_move_to_end(linked_list *l);
int ll_move_to_position(linked_list *l, int p);
int ll_previous(linked_list *l);
int ll_next(linked_list *l);
int ll_length(linked_list *l);
int ll_curr_position(linked_list *l);
int ll_get_value(linked_list *l);
void ll_delete_list(linked_list *l);

#endif
