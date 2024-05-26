#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce Vozlisce;

struct _Vozlisce {
    int vsebina; // »vsebina« vozlišča
    Vozlisce* desno; // kazalec na desnega soseda ( NULL v zadnjem stolpcu)
    Vozlisce* dol; // kazalec na spodnjega soseda ( NULL v zadnji vrstici)
};

Vozlisce* vstaviStolpec(Vozlisce* start, int mesto, int vsebina) {
    Vozlisce* sega = start;
    Vozlisce* pred = NULL;

    for (int i = 0; i < mesto; i++) {
        pred = sega;
        sega = sega->desno;
    }

    int v = vsebina;

    Vozlisce* prvo = malloc(sizeof(Vozlisce));

    prvo->vsebina = v;
    prvo->desno = sega;
    prvo->dol = NULL;

    v++;

    if (pred != NULL) {
        pred->desno = prvo;
    } else {
        start = prvo;
    }

    while (sega->dol != NULL) {
        sega = sega->dol;

        Vozlisce* novo = malloc(sizeof(Vozlisce));

        novo->vsebina = v;
        novo->desno = sega;
        novo->dol = NULL;

        prvo->dol = novo;
        prvo = novo;

        v++;
    }

    return start;
}

int main() {

    return 0;
}
