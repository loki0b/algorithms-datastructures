// Implements binary search
// Method: Decrease-and-Conquer (constant factor)
// Input: An array A[0..n - 1] sorted in ascending order, a search key and an array size
// Output: An index of the array's element tha is equal to K or -1 if there is no such element

#include <stddef.h>

// nonrecursive binary search
int binary_search(int *array, int k, size_t array_size) {
    int l, r;

    l = 0;
    r = array_size;
    while (l <= r) {
        int m;

        m = (l + r) / 2;
        if (k == array[m]) return m;
        else if (k < array[m]) r = m - 1;
        else l = m + 1;
    }

    return -1;
}

// TODO: recursive binary search
