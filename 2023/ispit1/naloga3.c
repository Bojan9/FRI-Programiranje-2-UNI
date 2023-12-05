
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -D=test testXY.c naloga3.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Testni primeri:
 * 02, 03: h = 1
 * 04, 05, 06: mesto = 0
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

// po potrebi dopolnite ...

// Vozlisce* vstaviStolpec(Vozlisce* start, int mesto, int vsebina) {
//     Vozlisce* pravo_mesto = start;
//     int vsebina_nova = vsebina;

//     if (mesto == 0) {
//         Vozlisce* pred = (Vozlisce*) malloc(sizeof(Vozlisce));
//         pred->vsebina = vsebina_nova;
//         pred->desno = pravo_mesto;
//         pred->dol = NULL;

//         start = pred;

//         vsebina_nova = vsebina_nova + 1;

//             while (pravo_mesto->dol != NULL) {
//             pravo_mesto = pravo_mesto->dol;

//             Vozlisce* novo = (Vozlisce*) malloc(sizeof(Vozlisce));
//             novo->vsebina = vsebina_nova;
//             novo->desno = pravo_mesto;
//             novo->dol = NULL;

//             pred->dol = novo;
//             pred = novo;
//             vsebina_nova = vsebina_nova + 1;
//         }
//     } else {
//         for (int i = 0; i < mesto-1; i++) {
//             pravo_mesto = pravo_mesto->desno;
//         }

//         Vozlisce* pred = (Vozlisce*) malloc(sizeof(Vozlisce));
//         pred->vsebina = vsebina_nova;
//         pred->desno = pravo_mesto->desno;
//         pred->dol = NULL;

//         pravo_mesto->desno = pred;
//         vsebina_nova = vsebina_nova + 1;

//         while (pravo_mesto->dol != NULL) {
//             pravo_mesto = pravo_mesto->dol;

//             Vozlisce* novo = (Vozlisce*) malloc(sizeof(Vozlisce));
//             novo->vsebina = vsebina_nova;
//             novo->desno = pravo_mesto->desno;
//             novo->dol = NULL;

//             pravo_mesto->desno = novo;

//             pred->dol = novo;
//             pred = novo;
//             vsebina_nova = vsebina_nova + 1;
//         }
//     }
//     return start;
// }

Vozlisce* vstaviStolpec(Vozlisce* start, int mesto, int vsebina) {
    Vozlisce* pravo_mesto = start;
    int vsebina_nova = vsebina;

    for (int i = 0; i < mesto-1; i++) {
        pravo_mesto = pravo_mesto->desno;
    }

    Vozlisce* pred = (Vozlisce*) malloc(sizeof(Vozlisce));
    pred->vsebina = vsebina_nova;
    pred->dol = NULL;
    if (mesto == 0) {
        pred->desno = pravo_mesto;
        start = pred;
    } else {
        pred->desno = pravo_mesto->desno;
        pravo_mesto->desno = pred;
    }

    vsebina_nova = vsebina_nova + 1;

    while (pravo_mesto->dol != NULL) {
        pravo_mesto = pravo_mesto->dol;

        Vozlisce* novo = (Vozlisce*) malloc(sizeof(Vozlisce));
        novo->vsebina = vsebina_nova;
        novo->dol = NULL;
        if (mesto == 0) {
            novo->desno = pravo_mesto;
        } else {
            novo->desno = pravo_mesto->desno;
            pravo_mesto->desno = novo;
        }

        pred->dol = novo;
        pred = novo;
        vsebina_nova = vsebina_nova + 1;
    }
    return start;
}

//=============================================================================

#ifndef test

#define _VISINA 100
#define _SIRINA 100

#define _RANDOM_A 691
#define _RANDOM_B 929
#define _MODULO 997

Vozlisce* _MATRIKA[_VISINA][_SIRINA];

int _mojRandom(int r) {
    return (_RANDOM_A * r + _RANDOM_B) % _MODULO;
}

void _napolni() {
    int r = 608;
    for (int i = 0; i < _VISINA; i++) {
        for (int j = 0; j < _SIRINA; j++) {
            _MATRIKA[i][j] = calloc(1, sizeof(Vozlisce));
            r = _mojRandom(r);
            _MATRIKA[i][j]->vsebina = r;
        }
    }
    for (int i = 0; i < _VISINA; i++) {
        for (int j = 0; j < _SIRINA; j++) {
            if (j < _SIRINA - 1) {
                _MATRIKA[i][j]->desno = _MATRIKA[i][j + 1];
            }
            if (i < _VISINA - 1) {
                _MATRIKA[i][j]->dol = _MATRIKA[i + 1][j];
            }
        }
    }
}

void _assert(bool b) {
    static bool ze = false;
    if (!b && !ze) {
        printf("\nNapaka -- izdelava kopije!\n");
        ze = true;
    }
}

void _preveri(Vozlisce* v0, int mesto) {
    if (mesto == 0) {
        Vozlisce* v = v0;
        for (int i = 0; i < _VISINA; i++) {
            _assert(v->desno == _MATRIKA[i][0]);
            v = v->dol;
        }
    } else {
        _assert(v0 == _MATRIKA[0][0]);
    }
    for (int i = 0; i < _VISINA; i++) {
        for (int j = 0; j < _SIRINA; j++) {
            _assert(_MATRIKA[i][j]->dol == ((i == _VISINA - 1) ? (NULL) : (_MATRIKA[i + 1][j])));
            if (j != mesto - 1) {
                _assert(_MATRIKA[i][j]->desno == ((j == _SIRINA - 1) ? (NULL) : (_MATRIKA[i][j + 1])));
            }
        }
    }
}

void _izpisi(Vozlisce* v0) {
    printf("Po vrsticah:\n");
    Vozlisce* v = v0;
    int i = 0;
    while (v != NULL) {
        printf("%d: [", i);
        Vozlisce* w = v;
        while (w != NULL) {
            if (w != v) {
                printf(", ");
            }
            printf("%d", w->vsebina);
            w = w->desno;
        }
        printf("]\n");
        v = v->dol;
        i++;
    }

    printf("\n");
    printf("Po stolpcih:\n");
    v = v0;
    i = 0;
    while (v != NULL) {
        printf("%d: [", i);
        Vozlisce* w = v;
        while (w != NULL) {
            if (w != v) {
                printf(", ");
            }
            printf("%d", w->vsebina);
            w = w->dol;
        }
        printf("]\n");
        v = v->desno;
        i++;
    }
}

void _pocisti(Vozlisce* v0) {
    Vozlisce* v = v0;
    while (v != NULL) {
        Vozlisce* w = v;
        while (w != NULL) {
            Vozlisce* temp = w->desno;
            free(w);
            w = temp;
        }
        v = v->dol;
    }
}

int main() {
    _napolni();
    int mesto = 10;
    int vsebina = 314;
    Vozlisce* v = vstaviStolpec(_MATRIKA[0][0], mesto, vsebina);

    _izpisi(v);
    _preveri(v, mesto);
    _pocisti(v);

    return 0;
}

#endif
