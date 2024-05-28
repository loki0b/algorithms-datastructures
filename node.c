#include <stdlib.h>

typedef struct link {
    int element;
    struct link *next_node;
} node;

node* create_node(node *next_node, int element) {
    node* n;

    n = (node*) malloc(sizeof (node));
    if (n == NULL) {
        return NULL;
    }
    n->element = element;
    n->next_node = next_node;

    return n;
}
