#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[31];
    int score;
    int age;
} candidate;

void merge(candidate *array, int l, int r, int n, int (*compare)(candidate, candidate));
void merge_sort(candidate *array, int l, int r, int n, int (*compare)(candidate, candidate));

int compare_score(candidate x, candidate y) { return (x.score >= y.score); }
int compare_age(candidate x, candidate y) { return (x.age >= y.age); }
int min(int a, int b) { return a < b ? a : b; }

int main(void) {
    int c;

    scanf("%d", &c);
    for (int x = 1; x <= c; x++) {
        int i, v;
        candidate *candidates;
        
        scanf("%d%d", &i, &v);
        candidates = (candidate*) malloc(sizeof(candidate) * i);
        for (int j = 0; j < i; j++) {
            scanf("%s%d%d", candidates[j].name, &candidates[j].score, &candidates[j].age);
        }
    
        merge_sort(candidates, 0, i - 1, i, compare_score);
        merge_sort(candidates, 0, i - 1, i, compare_age);

        printf("cargo %d:\n", x);
        int aux = min(i, v);
        for (int k = 0; k < aux; k++) printf("%s\n", candidates[k].name);
        for (int k = 0; k < v - i; k++) printf("x\n");

        free(candidates);

    }
    return 0;
}

void merge(candidate *array, int l, int r, int n, int (*compare)(candidate, candidate)) {
    int m;
    int i1, i2;
    candidate *temp_array;
    
    temp_array = malloc(sizeof (candidate) * n);
    for (int i = l; i <= r; i++) temp_array[i] = array[i];

    m = (l + r) / 2;
    i1 = l;
    i2 = m + 1;
    for (int curr = l; curr <= r; curr++) {
        if (i1 == m + 1) array[curr] = temp_array[i2++];
        else if (i2 > r) array[curr] = temp_array[i1++];
        else if (compare(temp_array[i1], temp_array[i2])) array[curr] = temp_array[i1++];
        else array[curr] = temp_array[i2++];
    }

    free(temp_array);
}

void merge_sort(candidate *array, int l, int r, int n, int (*compare)(candidate, candidate)) {
    if (l < r) {
        int m;
        
        m = (l + r) / 2;
        merge_sort(array, l, m, n, compare);
        merge_sort(array, m + 1, r, n, compare);
        merge(array, l, r, n, compare);
    }
}
