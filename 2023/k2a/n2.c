#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Vozlisce Vozlisce;

struct Vozlisce {
    int podatek;
    Vozlisce* naslednje;
};

void izlociSkupne(Vozlisce* a, Vozlisce* b, Vozlisce** na, Vozlisce** nb) {
    *na = a;
    *nb = b;

    Vozlisce* prev_a = NULL;
    Vozlisce* now_a = a;

    while (now_a != NULL) {
        Vozlisce* prev_b = NULL;
        Vozlisce* now_b = b;

        bool change = false;

        while (now_b != NULL) {
            if (now_a->podatek == now_b->podatek) {
                if (prev_a == NULL) {
                    *na = now_a->naslednje;
                } else {
                    prev_a->naslednje = now_a->naslednje;
                }

                if (prev_b == NULL) {
                    *nb = now_b->naslednje;
                    b = now_b->naslednje;
                } else {
                    prev_b->naslednje = now_b->naslednje;
                }

                change = true;
                break;

            } else {
                prev_b = now_b;
            }

            now_b = now_b->naslednje;
        }

        if (change == false) {
            prev_a = now_a;
        }
        
        now_a = now_a->naslednje;
    }
}

int main() {
    
    return 0;
}