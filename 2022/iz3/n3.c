#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct Vozlisce Vozlisce;

struct Vozlisce {
    int podatek;
    Vozlisce* levo;
    Vozlisce* desno;
};

Vozlisce* drevo(int n, int* podatki) {
    if (n <= 0) {
        return NULL;
    }

    int half = pow(2, n - 1);

    Vozlisce* koren = malloc(sizeof(Vozlisce));
    koren->podatek = podatki[0];
    koren->levo = drevo(n - 1, podatki + 1);
    koren->desno = drevo(n - 1, podatki + half);

    return koren;
}

int main() {

    return 0;
}