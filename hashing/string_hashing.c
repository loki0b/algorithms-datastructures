#include <string.h>
#include <stdlib.h>

#define M 100

int fold(char *string) {
    int n, sum;

    n = strlen(string);
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += string[i];
    }
    
    return abs(sum) % M;
}

// int sfold(char *string);
