#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
    struct _Vozlisce* n; // kazalec na naslednje vozlišče v verigi oz. NULL, če ga ni
    struct _Vozlisce* r; // kazalec na poljubno vozlišče v verigi ali NULL
} Vozlisce;

int najkrajsaPot(Vozlisce* izvor, Vozlisce* cilj) {
    if (izvor == cilj) {
        return 0;
    }

    int dolzina = 0;
    int found = 0;

    Vozlisce* vrsta[20];
    int zacetek = 0;
    int konec = 0;

    vrsta[konec++] = izvor;

    while (zacetek < konec) {
        int trenutno_nivo = konec - zacetek;
        dolzina++;

        while (trenutno_nivo > 0) {
            Vozlisce* trenutno = vrsta[zacetek++];

            if (trenutno->n == cilj || trenutno->r == cilj) {
                found = 1;
                break;
            }

            if (trenutno->n != NULL) {
                vrsta[konec++] = trenutno->r;
            }

            trenutno_nivo--;
        }
        if (found) {
            break;
        }
    }

    return dolzina;
}

int main() {
    
    return 0;
}