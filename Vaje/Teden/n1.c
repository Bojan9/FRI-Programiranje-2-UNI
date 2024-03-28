#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int vsota(int* zac, int* kon) {
    int rez = 0;

    for (int i = 0; zac[i] <= *kon; i++) {
        rez += zac[i];
    }

    return rez;
}

void indeksInKazalec(int* t, int* indeks, int** kazalec) {
    if (*indeks == -1) {
        int index = 0;
        while (*kazalec != &t[index]) {
            index++;
        }
        *indeks = index;
    } else {
        *kazalec = &t[*indeks];
    }
}

void frekvenceCrk(char* niz, int** frekvence) {
    int* tabela = calloc(26, sizeof(int));

    for (int i = 0; niz[i] != '\0'; i++) {
        char c = tolower(niz[i]);
        tabela[c-'a'] += 1;
    }

    *frekvence = &tabela[0];
}

// 1

int main() {
    int tab[]={1,2,3,4,5};
    int* zac=&tab[0];
    int* kon=&tab[4];
    printf("%d",vsota(zac,kon));

    return 0;
}

// 2

// int main() {
//     int* t = malloc(10 * sizeof(int));

//     int indeks = -1;
//     int* kazalec = t;
//     indeksInKazalec(t, &indeks, &kazalec);
//     printf("%d\n", indeks);

//     indeks = -1;
//     kazalec = t + 5;
//     indeksInKazalec(t, &indeks, &kazalec);
//     printf("%d\n", indeks);

//     indeks = -1;
//     kazalec = t + 9;
//     indeksInKazalec(t, &indeks, &kazalec);
//     printf("%d\n", indeks);

//     free(t);

//     exit(0);
//     return 0;
// }

// 3

// int main() {
//     int* frekvence;
//     frekvenceCrk("baNanA", &frekvence);
//     for (int c = 'A';  c <= 'Z';  c++) {
//         if (frekvence[c - 'A'] > 0) {
//             printf("%c -> %d\n", c, frekvence[c - 'A']);
//         }
//     }

//     free(frekvence);

//     exit(0);
//     return 0;
// }
