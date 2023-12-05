#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n;
    int suma = 0;
    int p = 1;

    scanf("%d", &n);

    int* niza = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &niza[i]);
    }

    for (int i = 0; i < n/2; i++) {
        suma = suma + niza[i] + niza[n-1-i];
        if (niza[i] != niza[n-1-i]) {
            p = 0;
        }
    }

    if (n % 2 != 0) {
        suma += niza[n/2];
    }

    if (p == 1) {
        printf("DA\n");
        printf("%d", suma);
    } else {
        printf("NE\n");
        printf("%d", suma);
    }

    free(niza);

    return 0;
}