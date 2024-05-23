// Sorts a given array by bubble sort
// Input: An array A[0..n - 1] of orderable elements
// Output: Array A[0.. n - 1] sorted in nondecreasing order
#include "../include/functions.h"

void bubble_sort(int *array, int array_size) {
    int n;

    n = array_size;
    for (int i = 0; i <= n - 2; i++) {
        for (int j = 0; j <= n - 2 - i; j++) {
            if (array[j + 1] < array[j]) swap(&array[j], &array[j + 1]);
        }
    }
}
