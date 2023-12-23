#ifndef _STACK_H_
#define _STACK_H_

typedef struct node Node;
typedef struct stack Stack;
Node* create_node(Node* node, int value);
Stack* create_stack();
void push(Stack* s, int value);
int pop(Stack* s);
void clear(Stack* s);
void delete_stack(Stack* s);
int top_value(Stack* s);
int length(Stack* s);

#endif
