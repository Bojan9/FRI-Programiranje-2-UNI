#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
    int podatek;
    struct _Vozlisce* naslednje;
} Vozlisce;

Vozlisce* izloci(Vozlisce* zac, Vozlisce* v) {
    if (zac == v) {
        zac = zac->naslednje;
        return zac;
    }

    Vozlisce* z = zac;
    Vozlisce* pred = NULL;

    while (z != NULL) {
        if (z == v) {
            pred->naslednje = z->naslednje;
            return zac;
        }

        pred = z;
        z = z->naslednje;
    }

    return zac;
}

int main() {
    
    return 0;
}