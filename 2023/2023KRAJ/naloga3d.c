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

Vozlisce* diagonala(Vozlisce* start, int* vsota) {
    int c = 0;
    Vozlisce* pravo = start;

    while (pravo->desno != NULL) {
        pravo = pravo->desno;
        c++;
    }

    Vozlisce* vrati = malloc(sizeof(Vozlisce));
    vrati->vsebina = pravo->vsebina;
    vrati->desno = NULL;
    vrati->dol = NULL;

    *vsota += vrati->vsebina;

    Vozlisce* pred = vrati;
    c--;

    while (start->dol != NULL) {
        start = start->dol;
        pravo = start;

        for (int i = 0; i < c; i++) {
            pravo = pravo->desno;
        }
        c--;

        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo->vsebina = pravo->vsebina;
        novo->desno = NULL;
        novo->dol = NULL;

        *vsota += novo->vsebina;

        pred->desno = novo;
        pred = novo;
    }
    return vrati;
}

int main() {
    return 0;
}