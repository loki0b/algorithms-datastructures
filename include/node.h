#ifndef NODE_H
#define NODE_H

typedef struct link {
    int element;
    struct link *next_node;
} node;

node* create_node(node *next_node, int element);

#endif
