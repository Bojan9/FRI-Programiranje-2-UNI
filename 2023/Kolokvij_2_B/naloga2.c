#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce Vozlisce;

struct _Vozlisce {
    int* p;
    Vozlisce* naslednje;
};

void izlociDuplikate(Vozlisce* zacetek) {
    while (zacetek != NULL) {
        Vozlisce* pred = zacetek;
        Vozlisce* j = zacetek->naslednje;

        while (j != NULL) {
            if (zacetek->p == j->p) {
                j = j->naslednje; 
                pred->naslednje = j;
            } else {
                pred = j;
                j = j->naslednje;
            }
        }

        zacetek = zacetek->naslednje;
    }
}

int main() {

    return 0;
}
