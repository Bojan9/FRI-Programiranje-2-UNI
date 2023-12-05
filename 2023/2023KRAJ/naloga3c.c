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
    Vozlisce* pravo = start;
    
    for (int i = 0; i < mesto-1; i++) {
        pravo = pravo->desno;
    }

    Vozlisce* pred = malloc(sizeof(Vozlisce));
    pred->vsebina = vsebina;
    pred->dol = NULL;
    if (mesto == 0) {
        pred->desno = pravo;
        start = pred;
    } else {
        pred->desno = pravo->desno;
        pravo->desno = pred;
    }

    vsebina++;

    while (pravo->dol != NULL) {
        pravo = pravo->dol;

        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo->vsebina = vsebina;
        novo->dol = NULL;
        if (mesto == 0) {
            novo->desno = pravo;
        } else {
            novo->desno = pravo->desno;
            pravo->desno = novo;
        }

        pred->dol = novo;
        pred = novo;
        vsebina++;
    }
    return start;
}

int main() {
    return 0;
}