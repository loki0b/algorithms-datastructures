#include <stdio.h>
#include "include/sort.h"
#include "include/search.h"
#include "include/list.h"

// TODO: how to create docs for functions in C?

int main(void) {
    stack* s = s_create_stack();
    s_push(s, 3);
    s_delete_stack(s);
    
    return 0;
}
