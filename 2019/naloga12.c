#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Vozlisce Vozlisce;
struct Vozlisce {
    int podatek;
    Vozlisce* naslednje;
};

Vozlisce* obrni(Vozlisce* zacetek) {
    Vozlisce* t = zacetek;
    Vozlisce* p = zacetek;
    Vozlisce* a = zacetek;

    int counter = 0;
    while (t != NULL) {
        t = t->naslednje;
        counter++;
    }

    int* tabela = malloc(counter * sizeof(int));
    for (int i = 0; i < counter; i++) {
        tabela[i] = p->podatek;
        p = p->naslednje;
    }

    for (int i = counter-1; i >= 0; i--) {
        a->podatek = tabela[i];
        a = a->naslednje;
    }

    return zacetek;
}

int main() {
    return 0;
}