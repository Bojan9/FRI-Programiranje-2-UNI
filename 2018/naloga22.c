#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce { // vozlišče povezanega seznama
    int podatek; // podatek v vozlišču
    struct _Vozlisce* n; // kazalec na naslednika ( NULL, če ga ni)
    struct _Vozlisce* nn; // kazalec na naslednika naslednika ( NULL, če ga ni)
} Vozlisce;

Vozlisce* create_vozlisce(Vozlisce *n, Vozlisce *nn, int podatek) {
    Vozlisce *p = malloc(sizeof(Vozlisce));
    p->podatek = podatek;
    p->n = n;
    p->nn = nn;

    return p;
}

Vozlisce* vstaviUrejeno(Vozlisce* zacetek, int element) {
    if (zacetek == NULL) {
        return create_vozlisce(NULL, NULL, element);
    }

    if (zacetek->podatek > element) {
        return create_vozlisce(zacetek, zacetek->n, element);
    }

    Vozlisce* p = zacetek;
    Vozlisce* pred = NULL;
    Vozlisce* ppred = NULL;

    while (p->n != NULL && p->n->podatek < element) {
        pred = p;
        p = p->n;
    }
    Vozlisce* novo = create_vozlisce(p->n, p->nn, element);
    p->n = novo;
    pred->nn = novo;

    if (pred != NULL) {
        pred->nn = p->n;
    }

    return zacetek;
}

int main() {
    return 0;
}