#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int indeks_naj(char* niza, int n) {
    int naj = 0;
    int idx = 0;

    for (int i = 0; i < n; i++) {
        if (niza[i] > naj) {
            naj = niza[i];
            idx = i;
        }
    }

    return idx;
}

void rek(char* niza, int n, int indent) {
    if (n == 0) {
        return;
    }

    if (n == 1) { 
        for (int i = 0; i < indent; i++) {
            printf(" ");
        }

        printf("%s\n", niza);
        return;
    }

    if (n > 1) {
        for (int i = 0; i < indent; i++) {
            printf(" ");
        }

        printf("%s\n", niza);

        int idx = indeks_naj(niza, n);

        char* leva = calloc(idx + 1, sizeof(char));
        char* pivot = calloc(1 + 1, sizeof(char));
        char* desna = calloc((n - idx - 1) + 1, sizeof(char));

        for (int i = 0; i < idx; i++) {
            leva[i] = niza[i];
        }

        pivot[0] = niza[idx];

        for (int i = 0; i < n - idx - 1; i++) {
            desna[i] = niza[i + idx + 1];
        }

        rek(leva, strlen(leva), indent);
        rek(pivot, strlen(pivot), indent + idx);
        rek(desna, strlen(desna), indent + idx + 1);
    }
}

int main() {
    char* niza = calloc(201, sizeof(char));

    scanf("%s", niza);

    int n = strlen(niza);

    rek(niza, n, 0);

    free(niza);

    return 0;
}

