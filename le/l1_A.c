#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void quick_sort(int *array, int l, int r);
int calculate_cost(int *array, int r, int array_size);

int main(void) {
    unsigned int n; // number of chocolate bars (2 <= n <= 3 * 10^5)
    unsigned int *a; // array with n integers (1 <= a_i <= 10^9)
    long long int sum; // sum of prices of chocolates

    scanf("%d", &n);
    a = (int*) malloc(sizeof (int) * n);
    sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    unsigned int m; // number of coupons
    unsigned int q; // coupons

    scanf("%d", &m);
    // the inputs will be unsorted so I will use the quick_sort which the average case is slightly better than the merge_sort and
    // we do not care about the position of equal elements
    quick_sort(a, 0, n - 1);
    
    //printing the discounts
    for (int i = 0; i < m; i++) {
        long long int cost;

        scanf("%d", &q);
        cost = sum - a[n - q]; // subtracting the q-th largest price;
        printf("%lld\n", cost);
    }

    free(a);
    return 0;
}


int hoare_partition(int *array, int l, int r);

void quick_sort(int *array, int l, int r) {
    if (l < r) {
        int s;

        s = hoare_partition(array, l, r);
        quick_sort(array, l, s - 1);
        quick_sort(array, s + 1, r);
    }
}

void swap(int *a, int *b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int hoare_partition(int *array, int l, int r) {
    int p, i, j;

    p = array[l];
    i = l;
    j = r + 1;

    
    do { 
        do { i++; } while (array[i] < p && i < r);
        do { j--; } while (array[j] > p);
        swap(&array[i], &array[j]);

    } while (i < j);

    swap(&array[i], &array[j]);
    swap(&array[l], &array[j]);
    
    return j;
}
