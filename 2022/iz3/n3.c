#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
    int podatek;
    struct _Vozlisce* levo;
    struct _Vozlisce* desno;
} Vozlisce;

Vozlisce* drevo(int n, int* podatki) {
    if (n <= 0) {
        return NULL;
    }

    Vozlisce* koren = malloc(sizeof(Vozlisce));

    int half = (1 << (n - 1)) - 1;

    koren->podatek = podatki[0];
    koren->levo = drevo(n - 1, podatki + 1);
    koren->desno = drevo(n - 1, podatki + half + 1);

    return koren;
}

void izpisi(Vozlisce* koren) {
    if (koren == NULL) {
        printf("-");
        return;
    }
    printf("%d", koren->podatek);
    if (koren->levo != NULL || koren->desno != NULL) {
        printf("[");
        izpisi(koren->levo);
        printf(", ");
        izpisi(koren->desno);
        printf("]");
    }
}

void pocisti(Vozlisce* koren) {
    if (koren != NULL) {
        pocisti(koren->levo);
        pocisti(koren->desno);
        free(koren);
    }
}

int main() {
    FILE* f = fopen("test01.dat", "r");
    int n = 0;
    fscanf(f, "%d", &n);
    int velikost = (1 << n) - 1;
    int* tabela = malloc(velikost * sizeof(int));
    for (int i = 0;  i < velikost;  i++) {
        fscanf(f, "%d", &tabela[i]);
    }
    fclose(f);

    Vozlisce* koren = drevo(n, tabela);
    izpisi(koren);
    printf("\n");
    pocisti(koren);
    free(tabela);

    return 0;
}