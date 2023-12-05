
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 *
 * Testni primeri:
 * 02--06: a = 1, b = n
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void rekurzija(char* niza, char* znak, int a, int b, int n, int pozicija, int broj) {
    if (broj >= a - 1) {
        for (int i = 0; i < n; i++) {
            printf("%c", niza[i]);

            if(znak[i] == true) {
                printf("|");
            }
        }
        printf("\n");

        if (broj + 1 >= b) {
            return;
        }
    }
    
    for (int i = pozicija + 1; i < n - 1; i++) {
        znak[i] = true;
        rekurzija(niza, znak, a, b, n, i, broj + 1);
        znak[i] = false;
    }
}

int main() {
    char* niza = (char*) malloc(16 * sizeof(char));
    bool* znak = (bool*) calloc(16, sizeof(bool));

    int a, b, n;
    scanf("%s %d %d", niza, &a, &b);

    n = strlen(niza);

    rekurzija(niza, znak, a, b, n, -1, 0);

    free(niza);
    free(znak);

    return 0;
}