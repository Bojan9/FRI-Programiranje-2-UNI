#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void rek(int d, int n, char* niza, int golema, int mala, int broj, char* zbor, int dolzina) {
    if (dolzina == n) {
        if (golema == 1 && mala == 1 && broj == 1) {
            printf("%s\n", zbor);
        }
        return;
    }

    for (int i = 0; i < d; i++) {
        int g1 = 0, m1 = 0, b1 = 0;

        zbor[dolzina] = niza[i];
        
        if (niza[i] >= 'A' && niza[i] <= 'Z' && golema != 1) {g1 = 1;}
        if (niza[i] >= 'a' && niza[i] <= 'z' && mala != 1) {m1 = 1;}
        if (niza[i] >= '0' && niza[i] <= '9' && broj != 1) {b1 = 1;}
        rek(d, n, niza, golema + g1, mala + m1, broj + b1, zbor, dolzina + 1);
    }
}

int main() {
    int d;
    int n;

    scanf("%d", &d);

    char* niza = malloc(d * sizeof(char));

    scanf("%s", niza);
    scanf("%d", &n);

    char* zbor = calloc(n, sizeof(char));

    rek(d, n, niza, 0, 0, 0, zbor, 0);

    return 0;
}