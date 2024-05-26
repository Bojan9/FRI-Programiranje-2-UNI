#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce Vozlisce;

struct _Vozlisce {
    int podatek;
    Vozlisce* naslednje;
};

void izlociSkupne(Vozlisce* a, Vozlisce* b, Vozlisce** na, Vozlisce** nb) {
    *na = a;
    *nb = b;

    Vozlisce* sega_a = a;
    Vozlisce* pred_a = NULL;

    while (sega_a != NULL) {
        Vozlisce* sega_b = b;
        Vozlisce* pred_b = NULL;
        int found = 0;

        while (sega_b != NULL) {
            if (sega_a->podatek == sega_b->podatek) {
                if (pred_a == NULL) {
                    *na = sega_a->naslednje;
                } else {
                    pred_a->naslednje = sega_a->naslednje;
                }

                if (pred_b == NULL) {
                    *nb = sega_b->naslednje;
                    b = sega_b->naslednje;
                } else {
                    pred_b->naslednje = sega_b->naslednje;
                }

                sega_a = sega_a->naslednje;
                sega_b = sega_b->naslednje;

                found = 1;
                break;

            } else {
                pred_b = sega_b;
                sega_b = sega_b->naslednje;
            }
        }

        if (found == 0) {
            pred_a = sega_a;
            sega_a = sega_a->naslednje;
        }
    }
}

int main() {

    return 0;
}