#include <stdio.h>
#include <stdlib.h>
#include "../search.h"

int main(void) {
    int n, m;
    int *array;

    printf("Array length: ");
    scanf("%d", &n);
    array = (int*) malloc(sizeof (int) * 4);
    
    printf("Elements: ");
    for (int i = 0; i < n; i++) scanf("%d", &array[i]);

    printf("How much numbers will be search: ");
    scanf("%d", &m);
    while (m > 0) {
        int v, a;
        
        scanf("%d", &v);
        a = binary_search(array, v, n - 1);
        if (a >= 0) printf("%d\n", a);
        else printf("x\n");
        m--;
    }

    free(array);
    return 0;
}
