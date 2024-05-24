#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
    int podatek;
    struct _Vozlisce* naslednje; // kazalec na naslednika ( NULL, če ga ni)
} Vozlisce;

Vozlisce* odstrani(Vozlisce* osnova, Vozlisce* indeksi) {
    Vozlisce* sega = osnova;
    Vozlisce* pred = NULL;

    int i = 0;

    if (indeksi->podatek == 0) {
        while (indeksi != NULL && indeksi->podatek == i) {
            sega = sega->naslednje;
            osnova = sega;
            pred = sega;
            indeksi = indeksi->naslednje;
            i++;
        }
    }

    while (sega != NULL) {
        if (indeksi->podatek == i) {
            pred->naslednje = sega->naslednje;
            indeksi = indeksi->naslednje;
        } else {
            pred = sega;
        }
        sega = sega->naslednje;
        i++;
    }

    return osnova;
}

int main() {

    return 0;
}