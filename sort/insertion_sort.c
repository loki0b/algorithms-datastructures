// Sorts a given array by insertion sort
// Input: An array A[0..n - 1] of n orderable elements
// Output: Array A[0..n - 1] sorted in nondecreasing orderinclude <stddef.h>

void insertion_sort(int *array, int array_size) {
    int n;

    n = array_size;
    for (int i = 1; i <= n - 1; i++) {
        int v, j;

        v = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > v) {
            array[j + 1] = array[j];
            j -= 1;
        }
        array[j + 1] = v;
    }
}
