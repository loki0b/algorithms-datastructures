#ifndef _LIST_H_
#define _LIST_H_

typedef struct list List;
List* create_list(int size);
void insert(List* l, int value);
void append(List* l, int value);
int pop(List* l);
void clear(List* l);
void delete_list(List* l);
void move_to_start(List* l);
void move_to_end(List* l);
void move_to_position(List* l);
void next(List* l);
void previous(List* l);
int length(List* l);
int get_value(List* l);

#endif
