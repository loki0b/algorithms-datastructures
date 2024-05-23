#include <stdio.h>
#include <stdlib.h>
#include "include/tools.h"
#include "include/sort.h"
#include "include/search.h"
#include "include/list.h"

#define SIZE 10
// TODO: how to create docs for functions in C?

int main(void) {
    array_list *l = create_list(SIZE);
    insert(l, 4);
    append(l, 3);
    append(l, 2);
    pop(l);
    
    for (int i = 0; i < length(l); i++) { 
        printf("%d, ", get_value(l, i));
    }
    printf("\n");
    
    delete_array_list(l);
    free(l);
    return 0;
}
