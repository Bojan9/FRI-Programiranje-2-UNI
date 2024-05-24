#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce { // vozlišče povezanega seznama
    int podatek; // podatek v vozlišču
    struct _Vozlisce* n; // kazalec na naslednika ( NULL, če ga ni)
    struct _Vozlisce* nn; // kazalec na naslednika naslednika ( NULL, če ga ni)
} Vozlisce;

Vozlisce* vstaviUrejeno(Vozlisce* zacetek, int element) {
    if (zacetek == NULL) {
        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo->podatek = element;
        novo->n = NULL;
        novo->nn = NULL;

        return novo;
    }

    if (zacetek->podatek > element) {
        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo->podatek = element;
        novo->n = zacetek;
        novo->nn = zacetek->n;

        return novo;
    }

    Vozlisce* p = zacetek;
    Vozlisce* pred = NULL;

    while (p->n != NULL && p->n->podatek < element) {
        pred = p;
        p = p->n;
    }

    Vozlisce* novo = malloc(sizeof(Vozlisce));
    novo->podatek = element;
    novo->n = p->n;
    novo->nn = p->nn;

    p->n = novo;
    pred->nn = novo;

    return zacetek;
    
}

int main() {

    return 0;
}