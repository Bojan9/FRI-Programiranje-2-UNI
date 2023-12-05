#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
    int podatek;
    struct _Vozlisce* naslednje; // kazalec na naslednika ( NULL, če ga ni)
} Vozlisce;

Vozlisce* odstrani(Vozlisce* osnova, Vozlisce* indeksi) {
    Vozlisce* p = osnova;
    Vozlisce* pred = NULL;

    int counter = 0;

    if (indeksi->podatek == 0) {
        while (indeksi != NULL && indeksi->podatek == counter) {
            p = p->naslednje;
            osnova = p;
            counter++;
            indeksi = indeksi->naslednje;
            pred = p;
        }
    }

    while (p != NULL) {
        if (indeksi != NULL && indeksi->podatek == counter) {
            indeksi = indeksi->naslednje;
            pred->naslednje = p->naslednje;

            if (indeksi == NULL) {
                break;
            }
        } else {
            pred = p;
        }
        counter++;
        p = p->naslednje;
    }

    return osnova;
}

int main() {
    return 0;
}