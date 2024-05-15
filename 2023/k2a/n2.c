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

    Vozlisce* predA = NULL;
    Vozlisce* segaA = a;
    while (segaA != NULL) {
        Vozlisce* predB = NULL;
        Vozlisce* segaB = b;

        while (segaB != NULL) {
            if (segaA->podatek == segaB->podatek) {
                
                if (segaA == a) {
                    a = a->naslednje;
                }

                if (segaB == b) {
                    b = b->naslednje;
                }

                if (predA != NULL) {
                    predA->naslednje = segaA->naslednje;
                }

                if (predB != NULL) {
                    predB->naslednje = segaB->naslednje;
                }
                segaA = NULL;
                segaB = NULL;
            } else {
                predB = segaB;
                segaB = segaB->naslednje;
            }
        }
        if (segaA != NULL) {
            predA = segaA;
        }
        if (predA != NULL) {
            segaA = predA->naslednje;
        } else {
            segaA = a;
        }
        *na = a;
        *nb = b;
    }
}

int main() {

    return 0;
}