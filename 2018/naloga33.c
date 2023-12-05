#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int memo[1000000];

void rek(a, b, n) {
    if (memo[n] == 0) {
        memo[n] = 1;
    }

    if (n == 0) {
        return;
    }

    rek(a, b, n/a);
    rek(a, b, n/b);
}

int main() {
    int a, b, n;

    scanf("%d %d %d", &a, &b, &n);

    rek(a, b, n);

    int suma = 0;

    for (int i = 0; i < 1000000; i++) {
        if (memo[i] != 0) {
            suma += 1;
        }
    }

    printf("%d", suma);

    return 0;
}