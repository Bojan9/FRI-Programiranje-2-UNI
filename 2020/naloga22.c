#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
    int podatek;
    struct _Vozlisce* naslednje;
} Vozlisce;

Vozlisce* izloci(Vozlisce* zac, Vozlisce* v) {
    Vozlisce* prvo = zac;

    if (zac == v) {
        prvo = zac->naslednje;
        zac->naslednje = NULL;
        zac->podatek = NULL;
        return prvo;
    } else if (v->naslednje == NULL) {
        while (zac->naslednje != v) {
            zac = zac->naslednje;
        }
        zac->naslednje = NULL;
        return prvo;
    } else {
        while (zac->naslednje != v) {
            zac = zac->naslednje;
        }   
        zac->naslednje = v->naslednje;
        zac->naslednje->naslednje = NULL;

        return prvo;
    }
}

int main() {
    return 0;
}