#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct e {
    char *key;
    char *value;
} entry;

entry* create_entry(char *key, char *value) {
    entry *e;
    
    e = (entry*) malloc(sizeof(entry));
    if (e == NULL) {
        return NULL;
    }
    e->key = strdup(key);
    e->value = strdup(value);

    return e;
}

typedef struct n {
    entry *element;
    struct n *next_node;
} node;

node* create_entry_node(node *next_node, entry *element) {
    node *n;

    n = (node*) malloc(sizeof (node));
    if (n == NULL) {
        return NULL;
    }
    n->element = element;
    n->next_node = next_node;

    return n;
}

typedef struct list {
    node *head;
    node *tail;
    node *curr;
    int length;
} entry_linked_list; 

entry_linked_list* create_entry_linked_list() {
    entry_linked_list *l;
    
    l = (entry_linked_list*) malloc(sizeof (entry_linked_list));
    if (l == NULL) {
        return NULL;
    }
    l->head = l->tail = l->curr = create_entry_node(NULL, NULL);
    l->length = 0;

    return l;
}

int entry_append(entry_linked_list *l, entry *element) {
    node *n;
    
    n = create_entry_node(NULL, element);
    if (n == NULL) {
        return -1;
    }
    l->tail->next_node = n; 
    l->tail = l->tail->next_node;
    l->length++;

    return 0;
}

int fold(char *string) {
    int n, sum;

    n = strlen(string);
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += string[i];
    }
    
    return abs(sum) % 100;
}

typedef struct d {
    int hash_table_size;
    int count_elements;
    entry_linked_list **hash_table;
    int (*hash)(char*);
} dict;

dict* create_dict(int size, int (*hash)(char*)) {
    dict *d;

    d = (dict*) malloc(sizeof (dict));
    if (d == NULL) {
        return NULL;
    }
    d->hash_table_size = size;
    d->count_elements = 0;
    d->hash_table = (entry_linked_list**) malloc(sizeof (entry_linked_list*) * size);
    for (int i = 0; i < size; i++) {
        d->hash_table[i] = create_entry_linked_list();
    }
    d->hash = hash;

    return d;
}

void dict_insert(dict *d, char *key, char *value) {
    int pos;
    entry_linked_list *l;
    entry *e;

    pos = d->hash(key);
    l = d->hash_table[pos];
    e = create_entry(key, value);
    entry_append(l, e);
    d->count_elements++;
}

entry* find(dict *d, char *key, char* value) {
    int pos;
    entry_linked_list *l;
    node *n;

    pos = d->hash(key);
    l = d->hash_table[pos];
    if (l->length == 0) {
        return NULL;
    }
    
    n = l->head->next_node;
    while(n->element->value != value && n->next_node != NULL) {
        n = n->next_node;
    }
    
    if(n->element->value == value) {
        return n->element;
    }

    return NULL;
}

int dict_remove(dict *d, char *key, char *value) {
    int pos;
    entry_linked_list *l;

    pos = d->hash(key);
    l = d->hash_table[pos];
    if (find(d, key, value) == NULL) {
        return -1;
    }

    

}

entry* get_entry(dict *d, char* key) {
    int pos;
    entry_linked_list *l;

    pos = d->hash(key);
    l = d->hash_table[pos];

    return l->head->next_node->element;
}

int main() {
    dict *d = create_dict(100, fold);
    dict_insert(d, "nome", "henrique");

    entry *e = get_entry(d, "nome");
    printf("%s: %s\n", e->key, e->value);
    if (find(d, "nome", "henrique") != NULL) printf("1\n");
    else printf("2\n");
}
