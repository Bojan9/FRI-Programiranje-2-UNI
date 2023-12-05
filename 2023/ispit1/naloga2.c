#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void rek(int n, int momentalna, int a, int b, int z, int* znaci, int pred) {
    if (momentalna == n && z >= a && z <= b) {
        for (int i = 0; i < z-1; i++) {
            printf("%d+", znaci[i]);
        } printf("%d \n", znaci[z-1]);
    }

    for (int i = 1; i <= n; i++) {
        if (momentalna + i <= n && i >= pred) {
            znaci[z] = i;
            rek(n, momentalna + i, a, b, z + 1, znaci, i);
        }
    }
}

int main() {
    int n, a, b;

    scanf("%d %d %d", &n, &a, &b);

    int* znaci = calloc(n, sizeof(int));

    rek(n, 0, a, b, 0, znaci, 0);

    return 0;
}
