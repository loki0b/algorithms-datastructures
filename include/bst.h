#ifndef BST_H
#define BST_H

typedef struct bst_node bst_node;
bst_node* create_bst_node(int key, char *str);
typedef struct bst bst;
bst* create_bst();

#endif
