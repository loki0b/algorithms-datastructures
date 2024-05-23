#include <stdio.h>
#include "include/sort.h"
#include "include/search.h"
#include "include/list.h"

// TODO: how to create docs for functions in C?

int main(void) {
    linked_list *l = ll_create_list();
    ll_append(l, 3);
    ll_delete_list(l);
    return 0;
}
