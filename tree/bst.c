#include <stdlib.h>

typedef struct bst_node {
    int key;
    char *str;
    struct bst_node *left;
    struct bst_node *rigth;
} bst_node;

typedef struct bst {
    bst_node *root;
    int node_count;
} bst;

bst_node* create_bst_node(int key, char *str) {
    bst_node *bn;

    bn = (bst_node*) malloc(sizeof(bst_node));
    if (bn == NULL) {
        return NULL;
    }
    bn->key = key;
    bn->str = str;
    bn->left = bn->rigth = NULL;

    return bn;
}

bst* create_bst() {
    bst* t;

    t = (bst*) malloc(sizeof(bst));
    if (t == NULL) {
        return NULL;
    }
    t->root = NULL;
    t->node_count = 0;

    return t;
}
