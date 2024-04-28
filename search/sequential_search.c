// Implements sequential search
// Method: Brute force
// Input: An array A of n elements, a search key K and the array size
// Output: The index of the first element A[0..n - 1] whose value is equal to K or -1 if no such element is found

// non sorted array sequential search
int sequential_search(int *array, int k, int array_size) {
    int i, n;
    
    n = array_size;
    i = 0;
    while (array[i] != k) {
        i++;
    }
    if (i < n) return i;
    else return -1;
}

// sorted array sequential search
int sorted_sequential_search(int *array, int k) {
    int i;

    i = 0;
    while (array[i] < k) {
        i++;
    }
    if (array[i] == k) return i;
    else return -1;
}
