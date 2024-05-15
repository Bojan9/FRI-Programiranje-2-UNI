#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int steviloInKta (char* niz, int k, int* indeks) {
    int velike = 0;
    int i = 0;

    while (niz[i] != '\0') {
        if (niz[i] >= 'A' && niz[i] <= 'Z') {
            velike++;

            if (velike == k) {
                *indeks = i;
            }
        }
        
        i++;
    }

    if (velike < k) {
        *indeks = -1;
    }

    return velike;
}

void indeksi (char* niz, int** t) {
    int indeks = 0;
    int br = steviloInKta(niz, 1, &indeks);

    int* tabela1 = calloc(br, sizeof(int));

    int i = 0, j = 0;
    while (niz[i] != '\0') {
        if (niz[i] >= 'A' && niz[i] <= 'Z') {
            tabela1[j] = i;
            j++;
        }
        i++;
    }

    int* tabela2 = calloc(br + 1, sizeof(int));

    for (int i = 0; i < br; i++) {
        tabela2[i] = tabela1[br - i - 1];
    } 

    tabela2[br] = -1;

    *t = &tabela2[0];
}

char** zadnje(char** nizi) {
    int len = 0;
    while (nizi[len] != NULL) {
        len++;
    }

    char** tabela = calloc(len, sizeof(char*));

    for (int i = 0; i < len; i++) {
        char* last = NULL;
        
        int j = 0;
        while (nizi[i][j] != '\0') {
            if (nizi[i][j] >= 'A' && nizi[i][j] <= 'Z') {
                last = &(nizi[i][j]);
            }
            j++;
        }

        tabela[i] = last;
    }

    return tabela;
}

char* NIZI[] = {
    "O vrbA! sreCnA, drAGA vAs dOmaCa,",
    "kjer hisa mojega stoji oceta;",
    "DE B UKA ZEJA ME IZ TVOJGA SVETA",
    "Speljala Ne Bila, Goljfiva Kaca!",
    NULL
};

int ST_NIZOV = sizeof(NIZI) / sizeof(char*) - 1;

int main() {
    char** t = zadnje(NIZI);
    for (int i = 0;  i < ST_NIZOV;  i++) {
        if (t[i] == NULL) {
            printf("NULL\n");
        } else {
            printf("%ld\n", t[i] - NIZI[i]);
        }
    }
    free(t);

    exit(0);
    return 0;
}
