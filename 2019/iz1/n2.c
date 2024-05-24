#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Vozlisce Vozlisce;

struct Vozlisce {
    int podatek;
    Vozlisce* naslednje;
};

Vozlisce* obrni(Vozlisce* zacetek) {
    Vozlisce* pred = NULL;
    Vozlisce* sega = NULL;
    Vozlisce* sledno = NULL;

    while(zacetek != NULL) {
        sledno = sega->naslednje;
        sega->naslednje = pred;
        pred = sega;
        sega = sledno;
    }

    return pred;
}

int main() {

    return 0;
}