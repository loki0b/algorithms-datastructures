void insertion_sort(int *array, int size) {
    int n;

    n = size;
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
