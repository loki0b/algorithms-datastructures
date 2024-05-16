// Sorts a subarray by quicksort
// Method: Divide-and-Conquer
// Input: Subarray of array A[0..n - 1], defined by its left and right indices l and r
// Output: Subarray A[l..r] sorted in nondecreasing order

#include "../include/tools.h"

int hoare_partition(int *array, int l, int r);

void quick_sort(int *array, int l, int r) {
    if (l < r) {
        int s; // split position

        s = hoare_partition(array, l, r);
        quick_sort(array, l, s - 1);
        quick_sort(array, s + 1, r);
    }
}

// Partitions a subarray by Hoare's algorithm, using the first element as a pivot
// Input: Subarray of array A[0..n - 1], defined by its left and right indices l and r (l < r)
// Output: Partition of A[a..r], with the split position returned as this function's value
int hoare_partition(int *array, int l, int r) {
    int p, i, j;

    p = array[l];
    i = l;
    j = r + 1;

    do {
        
        do {
            i++;
        } while (array[i] < p && i < r);
       
        do {
            j--;
        } while (array[j] > p);

        swap(&array[i], &array[j]);
    } while (i < j);

    swap(&array[i], &array[j]);
    swap(&array[l], &array[j]);

    return j;
}
