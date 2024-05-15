#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Vozlisce Vozlisce;
    
struct Vozlisce {
    int podatek; // podatek, ki ga hrani vozlišče
    Vozlisce* naslednje; // kazalec na naslednje vozlišče ( NULL, če ga ni)
};

int vsotaI(Vozlisce* zacetek) {
    int vk = 0;

    while (zacetek != NULL) {
        vk += zacetek->podatek;
        zacetek = zacetek->naslednje;
    }

    return vk;
}

int vsotaR(Vozlisce* zacetek) {
    if (zacetek == NULL) {
        return 0;
    } else {
        return zacetek->podatek + vsotaR(zacetek->naslednje);
    }
}

Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    Vozlisce* pred = NULL;
    Vozlisce* sega = zacetek;

    Vozlisce* novo = malloc(sizeof(Vozlisce));
    novo->podatek = element;

    while (sega != NULL) {
        if (sega->podatek > element) {
            if (pred == NULL) {
                novo->naslednje = zacetek;
                return novo;
            } else {
                pred->naslednje = novo;
                novo->naslednje = sega;
                return zacetek;
            }
        } else {
            pred = sega;
            sega = sega->naslednje;
        }
    }

    pred->naslednje = novo;
    novo->naslednje = NULL;
    return zacetek;
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {
    if (zacetek == NULL) {
        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo->podatek = element;
        novo->naslednje = NULL;
        return novo;
    }

    if (zacetek->podatek > element) {
        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo->podatek = element;
        novo->naslednje = zacetek;
        return novo;
    } else {
        zacetek->naslednje = vstaviUrejenoR(zacetek->naslednje, element);
        return zacetek;
    }
}

int main() {
    return 0;
}