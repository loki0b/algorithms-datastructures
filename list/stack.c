#include <stdlib.h>
#include "../include/types.h"

typedef struct list {
    node* top; // reference to the first element -> LIFO
    int length; 
} stack;

stack* s_create_stack() {
    stack *s;

    s = (stack*) malloc(sizeof (stack));
    if (s == NULL) {
        return NULL;
    }
    s->top = NULL;
    s->length = 0;

    return s;
}

int s_push(stack *s, int element) {
    node *n;

    n = create_node(s->top, element);
    if (n == NULL) {
        return -1;
    }
    s->top = n;
    s->length++;
    
    return 0;
}

int s_pop(stack *s) {
    if (s->top == NULL) {
        return -1;
    }

    int element;
    node* n;

    element = s->top->element;
    n = s->top;
    s->top = s->top->next_node;
    free(n);
    s->length--;

    return element;
}

void s_clear(stack *s) {
    node *n;

    while(s->top != NULL) {
        n = s->top;
        s->top = s->top->next_node;
        free(n);
    }
    s->length = 0;
}

int s_top_value(stack *s) {
    if (s->top == NULL) {
        return -1;
    }

    return s->top->element;
}

int s_length(stack *s) {
    return s->length;
}

void s_delete_stack(stack *s) {
    s_clear(s);
    free(s);
}
