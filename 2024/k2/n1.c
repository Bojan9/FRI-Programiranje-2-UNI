#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Vozlisce Vozlisce;

struct Vozlisce {
    Vozlisce* naslednje;
    Vozlisce* prejsnje;
};

void nastavi(Vozlisce* zacetek) {
    Vozlisce* pred = NULL;
    Vozlisce* sega = zacetek;

    while(sega != NULL) {
        sega->prejsnje = pred;
        pred = sega;
        sega = sega->naslednje;
    }
}

int main() {
    
    return 0;
}