#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int pojavitve(char* niz, char c, int* indeks) {
    int i = 0;
    int all = 0;

    while (niz[i] != '\0') {
        if (niz[i] == c) {
            if (all == 0) {
                *indeks = i;
            }
            all++;
        }
        i++;
    }

    if (all == 0) {
        *indeks = -1;
    }

    return all;
}

void naslednjaPojavitev(char* niz, int* indeks) {
    char c = niz[*indeks];
    int i = *indeks + 1;
    int najde = 0;

    while (niz[i] != '\0') {
        if (niz[i] == c) {
            najde = 1;
            *indeks = i;
            break; 
        }
        i++;
    }

    if (najde == 0) {
        *indeks = -1;
    }
}

char* kopijaPodniza(char* niz, char c, int k) {
    int start = 0;
    int end = 0;
    int indeks = 0;

    pojavitve(niz, c, &indeks);
    k--;

    while (k != 0) {
        naslednjaPojavitev(niz, &indeks);
        k--;
    }

    start = indeks;
    naslednjaPojavitev(niz, &indeks);
    end = indeks - 1;

    int size = end - start;
    char* tabela = calloc(size, sizeof(char));

    for (int i = 0; i < size; i++) {
        tabela[i] = niz[start + 1 + i];
    }

    return tabela;
}

char* NIZ = "O Vrba! srecna, draga vas domaca,";

int main() {
    char* podniz = kopijaPodniza(NIZ, ' ', 1);
    printf("\"%s\"\n", podniz);
    free(podniz);

    podniz = kopijaPodniza(NIZ, ' ', 2);
    printf("\"%s\"\n", podniz);
    free(podniz);

    podniz = kopijaPodniza(NIZ, 'a', 5);
    printf("\"%s\"\n", podniz);
    free(podniz);

    podniz = kopijaPodniza(NIZ, 'a', 6);
    printf("\"%s\"\n", podniz);
    free(podniz);

    exit(0);
    return 0;
}