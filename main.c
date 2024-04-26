#include <stdio.h>
#include "tools.h"
#include "sort.h"

int main(void) {
    int array[] = {3, 2, 1, 7, 4, 42, 13, 78, 5, 23, 111, 9, 8};
    size_t array_size = sizeof(array) / sizeof(array[0]);
    
    for (int i = 0; i < array_size; i++) printf("%d ", array[i]);
    printf("\n");
    //selection_sort(array, array_size);
    //bubble_sort(array, array_size);
    //insertion_sort(array, array_size);
    merge_sort(array, 0, array_size - 1); // array_size should be n - 1
    for (int i = 0; i < array_size; i++) printf("%d ", array[i]);
    printf("\n");

    return 0;
}
