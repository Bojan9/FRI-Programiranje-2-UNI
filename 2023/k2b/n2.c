#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Vozlisce Vozlisce;

struct Vozlisce {
    int* p;
    Vozlisce* naslednje;
};

void izlociDuplikate(Vozlisce* zacetek) {
    while (zacetek != NULL) {
        Vozlisce* pred = zacetek;
        Vozlisce* next = zacetek->naslednje;

        while (next != NULL) {
            if (zacetek->p == next->p) {
                pred->naslednje = next->naslednje;
            } else {
                pred = next;
            }
            next = next->naslednje;
        }

        zacetek = zacetek->naslednje;
    }
}

int main() {
    
    return 0;
}