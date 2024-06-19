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

Vozlisce* diagonala(Vozlisce* start, int* vsota) {
    Vozlisce* temp = start;
    int dolzina = 0;

    while (temp->desno != NULL) {
        dolzina++;
        temp = temp->desno;
    }

    Vozlisce* diagonala = malloc(sizeof(Vozlisce));
    diagonala->vsebina = temp->vsebina;
    diagonala->desno = NULL;
    diagonala->dol = NULL;

    Vozlisce* prev = diagonala;

    *vsota += temp->vsebina;

    dolzina--;

    while (dolzina >= 0 && start->dol != NULL) {
        start = start->dol;
        Vozlisce* temp = start;

        for (int i = 0; i < dolzina; i++) {
            temp = temp->desno;
        }

        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo->vsebina = temp->vsebina;
        novo->desno = NULL;
        novo->dol = NULL;

        prev->desno = novo;
        prev = novo;

        *vsota += temp->vsebina;

        dolzina--;
    }

    return diagonala;
}

int main() {
    
    return 0;
}