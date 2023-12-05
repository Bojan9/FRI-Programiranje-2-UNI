
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
 * 04, 05, 06: preverjajo samo vsoto
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

// po potrebi dopolnite ...

Vozlisce* diagonala(Vozlisce* start, int* vsota) {
    *vsota = 0;
    int w = 0;

    if(start == NULL)
        return NULL;

    Vozlisce* desni = start;

    while(desni->desno != NULL) {
        desni = desni->desno;
        w++;
    }

    Vozlisce* vrni = (Vozlisce*) malloc(sizeof(Vozlisce));
    vrni->dol = NULL;
    vrni->desno = NULL;
    vrni->vsebina = desni->vsebina;
    *vsota += vrni->vsebina;

    if(w == 0)
        return vrni;

    Vozlisce* zadnji = vrni;

    Vozlisce* trenutni_dol = start->dol;
    while(trenutni_dol != NULL) {
        Vozlisce* desno = trenutni_dol;
        int i = 0;

        while(i < w - 1) {
            i++;
            desno = desno->desno;
        }
        Vozlisce* novo = (Vozlisce*) malloc(sizeof(Vozlisce));
        novo->vsebina = desno->vsebina;
        novo->desno = NULL;
        novo->dol = NULL;

        zadnji->desno = novo;
        zadnji = novo;
        *vsota += zadnji->vsebina;
        w--;

        if(w <= 0)
            break;

        trenutni_dol = trenutni_dol->dol;
    } 

    return vrni;
}

//=============================================================================

#ifndef test

#define _VISINA 12
#define _SIRINA 21

#define _RANDOM_A 691
#define _RANDOM_B 929
#define _MODULO 997

Vozlisce* _MATRIKA[_VISINA][_SIRINA];

int _mojRandom(int r) {
    return (_RANDOM_A * r + _RANDOM_B) % _MODULO;
}

void _napolni() {
    int r = 731;
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

void _izpisiDiagonalo(Vozlisce* v) {
    printf("Diagonala:\n");
    printf("[");
    Vozlisce* w = v;
    while (w != NULL) {
        if (w != v) {
            printf(", ");
        }
        printf("%d", w->vsebina);
        w = w->desno;
    }
    printf("]\n\n");
}

void _izpisiOriginal(Vozlisce* v0) {
    printf("Originalna matrika -- po vrsticah:\n");
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
    printf("Originalna matrika -- po stolpcih:\n");
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

void _pocistiDiagonalo(Vozlisce* v) {
    while (v != NULL) {
        Vozlisce* temp = v->desno;
        free(v);
        v = temp;
    }
}

void _pocistiOriginal(Vozlisce* v0) {
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
    int vsota = 0;
    Vozlisce* diag = diagonala(_MATRIKA[0][0], &vsota);

    printf("vsota = %d\n\n", vsota);

    _izpisiDiagonalo(diag);
    _izpisiOriginal(_MATRIKA[0][0]);

    _pocistiDiagonalo(diag);
    _pocistiOriginal(_MATRIKA[0][0]);

    return 0;
}

#endif