// Sorts array A[0..n - 1] by recursive mergesort
// Method: Divide-and-Conquer
// Input: An array A[0..n - 1] of orderable elements
// Output: An array A[0..n - 1] sorted in nondecreasing order

#include <stdlib.h>

void merge(int *array, int l, int r) {  // l -> the index 0 of this part of this array, r -> the lenght of this part of the array
    int m; // the median index of the array
    int i1, i2; // auxiliar index;
    int *temp_array;
    
    temp_array = malloc(sizeof (int) * (r + 1));
    for (int i = l; i <= r; i++) temp_array[i] = array[i]; // copying

    m = (l + r) / 2;
    i1 = l;
    i2 = m + 1;
    for (int curr = l; curr <= r; curr++) {
        if (i1 == m + 1) array[curr] = temp_array[i2++];
        else if (i2 > r) array[curr] = temp_array[i1++];
        else if (temp_array[i1] <= temp_array[i2]) array[curr] = temp_array[i1++];
        else array[curr] = temp_array[i2++];
    }

    free(temp_array);
}

void merge_sort(int *array, int l, int r) { // l -> the leftmost index of the array, r -> the rightmost index of the array
    if (l < r) {
        int m; // the median index of the array
        
        m = (l + r) / 2;
        merge_sort(array, l, m);
        merge_sort(array, m + 1, r);
        merge(array, l, r);
    }
}
