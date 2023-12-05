#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
    int* vTabelo; // kazalec na nek element tabele t
    struct _Vozlisce* naslednje; // kazalec na naslednje vozlišče seznama
} Vozlisce;

Vozlisce* create_vozlisce(int* vTabelo, Vozlisce* naslednje) {
    Vozlisce* p = malloc(sizeof(Vozlisce));

    p->vTabelo = vTabelo;
    p->naslednje = naslednje;

    return p;
}

Vozlisce** tabelaSeznamov(int* t, int d, int n) {
    Vozlisce** tabela = calloc(n, sizeof(Vozlisce*));
    Vozlisce* trenutno = NULL;
    int korak = 1;

    for (int i = 0; i < n; i++) {
        tabela[i] = create_vozlisce(t + korak - 1, NULL);
        trenutno = tabela[i];

        for (int j = 2 * korak - 1; j < d; j += korak) {
            trenutno->naslednje = create_vozlisce(t + j, NULL);
            trenutno = trenutno->naslednje;
        }
        korak = korak * 2;
    }
    return tabela;
}

int main() {
    return 0;
}