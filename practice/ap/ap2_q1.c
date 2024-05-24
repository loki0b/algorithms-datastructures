#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"

int main(void) {
    int c;

    printf("Number of cases: ");
    scanf("%d", &c);
    while (c > 0) {
        int n;
        int *array;
        size_t array_size;
        
        printf("How much elements: ");
        scanf("%d", &n);
        array = (int*) malloc(sizeof(int) * n);

        printf("Elements: ");
        for (int i = 0; i < n; i++) scanf("%d", &array[i]);
        quick_sort(array, 0, n - 1);    

        printf("Sorted array: ");
        for (int i = 0; i < n; i++) printf("%d ", array[i]);
        printf("\n");

        free(array);
        c--;
    }

    return 0;
}
