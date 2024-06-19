#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Vozlisce Vozlisce;

struct Vozlisce {
    char* niz;
    Vozlisce* naslednje;
};

void vstaviH1(Vozlisce* zacetek) {
    Vozlisce* pred = NULL;
    Vozlisce* sega = zacetek;

    while (sega != NULL) {
        if ((pred == NULL || strlen(pred->niz) == 0) && strlen(sega->niz) != 0 && (sega->naslednje == NULL || strlen(sega->naslednje->niz) == 0)) {
            int n = strlen(sega->niz);
            char* nova = calloc(n + 10, sizeof(char));

            nova[0] = '<';
            nova[1] = 'h';
            nova[2] = '1';
            nova[3] = '>';

            for (int i = 0; i < n; i++) {
                nova[i + 4] = sega->niz[i];
            }

            nova[n + 4] = '<';
            nova[n + 5] = '/';
            nova[n + 6] = 'h';
            nova[n + 7] = '1';
            nova[n + 8] = '>';

            sega->niz = nova;
        }
        pred = sega;
        sega = sega->naslednje;
    }
}

int main() {

    return 0;
}