#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Vozlisce Vozlisce;

struct Vozlisce {
    int podatek;
    Vozlisce* naslednje;
};

void obdelaj(Vozlisce* zacetek, int k) {
    Vozlisce* start_k = zacetek;

    Vozlisce* sega = zacetek;
    Vozlisce* pred = NULL;

    int vk = 0;

    for (int i = 0; i < k; i++) {
        vk += sega->podatek;
        pred = sega;
        sega = sega->naslednje;
    }

    while (sega != NULL) {
        if (vk == sega->podatek) {
            pred->naslednje = sega->naslednje;
            sega = sega->naslednje;
        } else {
            vk -= start_k->podatek;
            start_k = start_k->naslednje;

            vk += sega->podatek;
            pred = sega;
            sega = sega->naslednje;
        }
    }
}

int main() {

    return 0;
}