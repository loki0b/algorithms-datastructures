#include <stdio.h>
#include <stdlib.h>

int binary_search(int *array, int k, size_t array_size, int i);
void quick_sort(int *array, int l, int r);
void swap(int *a, int *b);

int main(void) {
    int n, k; // n <= 10^5
    int *a; // array of n numbers

    scanf("%d%d", &n, &k);
    a = (int*) malloc(sizeof (int) * n);
    for (int i = 0; i < n; i++) { scanf("%d", &a[i]); }
    
    int c;

    c = 0;
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        int index, y; 

        y = a[i] + k; // y is the number that is the absolute difference equal to the k when y - a[i]
        index = binary_search(a, y, n, i); // starting binary search from index i since the y must be greater than i
        if (index != -1) { c++; }
    }
    printf("%d\n", c);
    
    free(a);
    return 0;
}

int binary_search(int *array, int k, size_t array_size, int i) {
    int l, r;

    l = i;
    r = array_size;
    while (l <= r) {
        int m;

        m = (l + r) / 2;
        if (k == array[m]) { return m; }
        else if (k < array[m]) { r = m - 1; }
        else { l = m + 1; }
    }

    return -1;
}

void swap(int *a, int *b) { int temp = *a; *a = *b; *b = temp; }

int hoare_partition(int *array, int l, int r);

void quick_sort(int *array, int l, int r) {
    if (l < r) {
        int s;

        s = hoare_partition(array, l, r);
        quick_sort(array, l, s - 1);
        quick_sort(array, s + 1, r);
    }
}

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
