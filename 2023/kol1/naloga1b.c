#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n;
    int suma = 0;

    scanf("%d", &n);

    int* t1 = malloc (n * sizeof(int));
    int* t2 = malloc (n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &t1[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &t2[i]);
    }

    for (int i = 0; i < n; i++) {
        suma += (t1[i] - t2[i]) * (t1[i] - t2[i]);
    }

    printf("%d", suma);

    free(t1);
    free(t2);

    return 0;
}