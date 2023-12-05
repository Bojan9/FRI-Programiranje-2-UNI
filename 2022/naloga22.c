#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
    struct _Vozlisce* naslednje;
} Vozlisce;

int dolzinaCikla(Vozlisce* zacetek) {
    Vozlisce* tabela[1001];
    int c = 0;

    for (int i = 0; i < 1001; i++) {
        tabela[i] = zacetek;
        zacetek = zacetek->naslednje;
    }

    for (int i = 0; i < 1001; i++) {
        for (int j = i + 1; j < 1001; j++) {
            if (tabela[i] == tabela[j]) {
                c = j - i;
                return c;
            }
        }
    }
    return c;
}

int main() {
    return 0;
}