#include "../tools.h"
#include <stddef.h>

// Sorts a given array by selection sort
// Input: An array A[0..n - 1] of orderable elements
// Output: Array A[0..n - 1] sorted in nondecreasing order
void selection_sort(int *array, size_t array_size) {
    size_t n;
    
    n = array_size;
    for (int i = 0; i <= n - 2; i++) {
        int min = i;

        for (int j = i + 1; j <= n - 1; j++) {
            if (array[j] < array[min]) min = j;
        }
        swap(&array[i], &array[min]);
    }
}
