#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
    int* vTabelo; // kazalec na nek element tabele t
    struct _Vozlisce* naslednje; // kazalec na naslednje vozlišče seznama
} Vozlisce;

Vozlisce** tabelaSeznamov(int* t, int d, int n) {
    Vozlisce** rezultat = malloc(n * sizeof(Vozlisce*));
    int c = 1;

    for (int i = 0; i < n; i++) {
        Vozlisce* prvo = malloc(sizeof(Vozlisce));
        prvo->vTabelo = t + c - 1;
        prvo->naslednje = NULL;

        rezultat[i] = prvo;

        for (int j = 2 * c - 1; j < d; j += c) {
            Vozlisce* novo = malloc(sizeof(Vozlisce));
            novo->vTabelo = t + j;
            novo->naslednje = NULL;

            prvo->naslednje = novo;
            prvo = novo;
        }
        c = c * 2;
    }

    return rezultat;
}

int main() {

    return 0;
}