#include <stddef.h>
#include "../tools.h"


size_t hoare_partition(int *array, size_t l, size_t r) {
    int p, i, j;

    p = array[l];
    i = l;
    j = r + 1;
    do {
        
        do {
            i++;
        } while ( !(array[i] >= p || i >= r) );
       
        do {
            j--;
        } while ( !(array[j] <= p) );

        swap(&array[i], &array[j]);
    } while ( !(i >= j) );

    swap(&array[i], &array[j]);
    swap(&array[l], &array[j]);

    return j;
}

void quick_sort(int *array, size_t l, size_t r) {
    if (l < r) {
        size_t s; // split position

        s = hoare_partition(array, l, r);
        quick_sort(array, l, s - 1);
        quick_sort(array, s + 1, r);
    }
}
