#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void pretvori(unsigned char *znaki, unsigned char *izhod, int n) {

    for (int i = 0; i < n; i++) {
        int trenutni = znaki[i];
        izhod[i * 2] = ((trenutni / 16) + '0');
        if (trenutni % 16 >= 10) {
            izhod[i * 2 + 1] = ((trenutni % 16) - 10) + 'A';
        } else {
            izhod[i * 2 + 1] = trenutni % 16 + '0';
        }
    }
}

int main(int argc, char** argv) {
    FILE* vhod = fopen(argv[1], "rb");
    int n = atoi(argv[2]);
    FILE* izhod = fopen(argv[3], "w");

    unsigned char* znaki = malloc(n * sizeof(unsigned char));
    unsigned char* izpis = malloc(n * 2 * sizeof(unsigned char));

    for (int i = 0; i < n; i++) {
        znaki[i] = fgetc(vhod);
    }

    pretvori(znaki, izpis, n);
    for (int i = 0; i < n; i++) {
        fputc(izpis[i * 2], izhod);
        fputc(izpis[i * 2 + 1], izhod);
        if (i != n - 1)
            fputc('\n', izhod);
    }

    fclose(vhod);
    fclose(izhod);
    free(znaki);
    free(izpis);

    return 0;
}