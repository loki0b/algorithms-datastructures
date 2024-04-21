#include "../tools.h"

void bubble_sort(int *array, int size) {
    int n;

    n = size;
    for (int i = 0; i <= n -2; i++) {
        for (int j = 0; j <= n - 2 - i; j++) {
            if (array[j + 1] < array[j]) swap(&array[j], &array[j + 1]);
        }
    }
}
