#include <stdlib.h>
#include <string.h>

typedef struct bst_node {
    int key;
    char *str;
    struct bst_node *left;
    struct bst_node *right;
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
    bn->str = strdup(str);
    bn->left = bn->right = NULL;

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

char* find(bst *t, int key) {
    return findhelp(t->root, key);
}

char* find_help(bst_node *rt, int key) {
    if (rt == NULL) {
        return -1;
    }

    if (rt->key > key) {
        return find_help(rt->left, key)
    }
    else if (rt->key == key) {
        return rt->str;
    }
    else {
        return find_help(rt->right, key)
    }
}

void insert(bst *t, int key, char *str) {
    t->root = insert_help(t->root, key, str);
    t->node_count++;
}

bst_node insert_help(bst_node *rt, int key, char *str) {
    if (rt == NULL) {
        return create_bst_node(key, str);
    }

    if (rt->key > key) {
        rt->left = insert_help(rt->left, key, str);
    }
    else {
        rt->right = insert_help(rt->right, key, str);
    }

    return rt;
}

bst_node* get_min(bst_node *rt) {
    if (rt->left == NULL) {
        return rt;
    }

    return get_min(rt->left);
}

bst_node* delete_min(bst_node *rt) {
    if (rt->left == NULL) {
        return rt->right;
    }
    rt->left = delete_min(rt->left);

    return rt;
}

char* remove(bst *t, int key) {
    char *temp = find_help(t->root, key);
    if (temp != NULL) {
        t->root = remove_help(t->root, key);
        t->node_count--;
    }

    return temp;
}

bst_node* remove_help(bst_node *rt, int key) {
    if (rt == NULL) {
        return NULL
    }

    if (rt->key > key) {
        rt->left = remove_help(rt->left, key);
    }
    else if (rt->key < key) {
        rt->right = remove_help(rt->right, key);
    }
    else {
        if (rt->left == NULL) {
            return rt->right;
        }
        else if (rt->right == NULL) {
            return rt->left;
        }
        else {
            bst_node *temp = get_min(rt->right);
            rt->str = temp->str;
            rt->key = temp->key;
            rt->right = delete_min(rt->right);
        }
    }

    return rt;
}
