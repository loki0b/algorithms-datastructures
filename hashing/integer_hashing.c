#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define M 100

int integer_hash(int k) {
    return abs(k % M);
}

int mid_square_hash(int k) {
    int square;

    square = k * k;
    printf("%d\n", square);
    if (square < 100) {
        return square;
    } 
    else {
        int len, i, hash;
        char str[10000], str_n[3];

        sprintf(str, "%d", square);
        i = strlen(str) / 2;
        str_n[0] = str[i - 1];
        str_n[1] = str[i];
        str_n[2] = '\0';
        hash = atoi(str_n);

        return hash;
    }
}
