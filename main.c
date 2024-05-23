#include <stdio.h>
#include <stdlib.h>
#include "include/tools.h"
#include "include/sort.h"
#include "include/search.h"
#include "include/list.h"

#define SIZE 10
// TODO: how to create docs for functions in C?

int main(void) {
    linked_list *l = ll_create_list();
    ll_insert(l, 3);
    ll_delete_list(l);
    return 0;
}
