#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void rek(int n, int a, int b, int* niza, int suma, int x, int pred) {
    if (suma == n && x >= a && x <= b) {
        for (int i = 0; i < x-1; i++) {
            printf("%d+", niza[i]);
        }printf("%d\n", niza[x-1]);
    }

    for (int i = 1; i <= n; i++) {
        if (suma + i <= n && i >= pred) {
            niza[x] = i;
            rek(n, a, b, niza, suma + i, x + 1, i);
        }
    }
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    int* niza = malloc(b * sizeof(int));

    rek(n, a, b, niza, 0, 0, 0);

    return 0;
}