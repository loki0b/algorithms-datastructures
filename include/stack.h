#ifndef STACK_H
#define STACK_H

typedef struct list stack;
stack* s_create_stack();
int s_push(stack *s, int element);
int s_pop(stack *s);
int s_clear(stack *s);
int s_top_value(stack *s);
int s_length(stack *s);
void s_delete_stack(stack *s);

#endif
