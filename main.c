#include <stdio.h>
#include "include/node.h"
#include "include/queue.h"

// TODO: how to create docs for functions in C?

int main(void) {
    queue *q = create_queue();
    enqueue(q, 3);
    printf("%d\n", front_value(q));
    dequeue(q);
    return 0;
}
