#include <stdlib.h>

typedef struct list {
    int max_size; // capacity
    int list_size; // number of elements
    int curr; // position of the cursor
    int *array_list; // array with values
} array_list;

// create a new array_list
array_list* al_create_list(int size) {
    array_list *l = (array_list*) malloc(sizeof (array_list));
    if (l == NULL) { 
        return NULL; 
    }
    
    l->max_size = size;
    l->list_size = l->curr = 0;
    l->array_list = (int*) malloc(sizeof (int) * size);

    return l;
}

// inserts a new element in curr postion in the array list
int al_insert(array_list *l, int element) {
    if (l->list_size >= l->max_size) {
        return -1; 
    }
    
    int i;
    
    i = l->list_size;
    while(i > l->curr) {
        l->array_list[i] = l->array_list[i - 1];
        i--;
    }
    l->array_list[l->curr] = element;
    l->list_size++;

    return 0;
}

// insert a new element in the final of array list
int al_append(array_list *l, int element) {
    if (l->list_size >= l->max_size) { return -1; } // error
    
    l->array_list[l->list_size] = element;
    l->list_size++;

    return 0;
}

// remove an element in the curr position, then return it
int al_pop(array_list *l) {
    if (l->list_size == 0) {
        return -1;
    }

    int i, r;

    r = l->array_list[l->curr];
    i = l->curr;
    while (i < l->list_size) {
        l->array_list[i] = l->array_list[i + 1];
        i++;
    }
    l->list_size--;

    return r;
}

// clear the array list
void al_clear(array_list *l) {
    l->list_size = 0;
    l->curr = 0;
}

// move the curr
void al_move_to_start(array_list *l) {
    l->curr = 0;
}

void al_move_to_end(array_list *l) {
    l->curr = l->list_size;
}

int al_move_to_position(array_list *l, int p) {
    if (p < 0 || p > l->list_size) {
        return -1;
    }

    l->curr = p;

    return 0;
}

int al_previous(array_list *l) {
    if (l->curr == 0) {
        return -1;
    }

    l->curr--;

    return 0;
}

int al_next(array_list *l) {
    if (l->curr >= l->list_size) {
        return -1;
    }

    l->curr++;

    return 0;
}

int al_length(array_list *l) { 
    return l->list_size;
}

int al_curr_position(array_list *l) {
    return l->curr;
}

int al_get_value(array_list *l) {
    if (l->list_size == 0) {
        return -1;
    }
    
    return l->array_list[l->curr];
}

// free the array of the list struct
void al_delete_list(array_list *l) {
    free(l->array_list);
}
