#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct _Vozlisce {
    int podatek;
    struct _Vozlisce* levo;
    struct _Vozlisce* desno;
} Vozlisce;

Vozlisce* create_vozlisce(int podatek, Vozlisce* levo, Vozlisce* desno) {
    Vozlisce* p = malloc(sizeof(Vozlisce));
    p->podatek = podatek;
    p->levo = levo;
    p->desno = desno;

    return p;
}

Vozlisce* drevo(int n, int* podatki) {
    if (n = 1) {
        Vozlisce* p = create_vozlisce(*podatki, NULL, NULL);
    }

    int half = pow(2, n-1);

    Vozlisce* koren = create_vozlisce(*podatki, drevo(n - 1, podatki + 1), drevo(n - 1, podatki + half));

    return koren;
}

int main() {
    return 0;
}