#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Vozlisce Vozlisce;

struct Vozlisce {
    int podatek;
    Vozlisce* naslednje;
};

Vozlisce* zlij(Vozlisce* a, Vozlisce* b) {
    Vozlisce* novo = malloc(sizeof(Vozlisce));
    Vozlisce* sega = novo;

    while (a != NULL && b != NULL) {
        if (a->podatek < b->podatek) {
            sega->naslednje = a;
            a = a->naslednje;
        } else {
            sega->naslednje = b;
            b = b->naslednje;
        }
        sega = sega->naslednje;
    }

    if (a == NULL) {
        sega->naslednje = b;
    } else {
        sega->naslednje = a;
    }

    return novo->naslednje;
}

int main() {
    
    return 0;
}