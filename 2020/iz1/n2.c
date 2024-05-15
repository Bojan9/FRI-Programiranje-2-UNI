#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Vozlisce Vozlisce;

struct Vozlisce {
    int vrednost;
    Vozlisce* naslednje;
};

Vozlisce* prepisi(int* t) {
    if (t == NULL || *t == 0) {
        return NULL;
    }

    Vozlisce* prv = NULL;
    Vozlisce* pred = NULL;

    while (*t != 0) {
        Vozlisce* sega = malloc(sizeof(Vozlisce));
        sega->vrednost = *t;
        sega->naslednje = NULL;

        if (prv == NULL) {
            prv = sega;
            pred = sega;
        } else {
            pred->naslednje = sega;
            pred = sega;
        }

        t++;
    }

    return prv;
}

int main() {

    return 0;
}