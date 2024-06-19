#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Vozlisce Vozlisce;

struct Vozlisce {
    int vsebina;
    Vozlisce* desno;
    Vozlisce* dol;
};

Vozlisce* vstaviStolpec(Vozlisce* start, int mesto, int vsebina) {
    Vozlisce* temp = start;

    for (int i = 0; i < mesto - 1; i++) {
        temp = temp->desno;
    }

    Vozlisce* prev = malloc(sizeof(Vozlisce));
    prev->vsebina = vsebina;
    if (mesto == 0) {
        prev->desno = temp;
        start = prev;
    } else {
        prev->desno = temp->desno;
        temp->desno = prev;
    }
    prev->dol = NULL;

    while (temp->dol != NULL) {
        temp = temp->dol;

        vsebina++;

        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo->vsebina = vsebina;
        if (mesto == 0) {
            novo->desno = temp;
        } else {
            novo->desno = temp->desno;
            temp->desno = novo;
        }
        novo->dol = NULL;

        prev->dol = novo;
        prev = novo;
    }
    
    return start;
}

int main() {
    
    return 0;
}