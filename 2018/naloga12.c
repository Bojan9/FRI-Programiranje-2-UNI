#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

unsigned char *preberi(char *ime_datoteke, int *sirina, int *visina, int *st_bajtov) {   
    FILE *vhod = fopen(ime_datoteke, "rb");
    char *smeti = malloc(10 * sizeof(char));

    fgets(smeti, 10, vhod);
    fscanf(vhod, "%d%d", sirina, visina);
    fgetc(vhod);
    fgets(smeti, 10, vhod);

    *st_bajtov = (*visina) * (*sirina) * 3;
    unsigned char *pixli = malloc((*visina) * (*sirina) * 3 * sizeof(unsigned char));
    fread(pixli, sizeof(unsigned char), (3 * (*visina) * (*sirina)), vhod);

    fclose(vhod);
    return pixli;
}

int sivina(unsigned char *pixli, int sirina, int visina, int vrstica, int stolpec) {
    int R = pixli[(sirina * vrstica + stolpec ) * 3];
    int G = pixli[(sirina * vrstica + stolpec ) * 3 + 1];
    int B = pixli[(sirina * vrstica + stolpec ) * 3 + 2];

    int gray = (R + G + B) / 3;

    return gray;
}

int main(int argc, char **argv) {
    int *sirina = malloc(sizeof(int));
    int *visina = malloc(sizeof(int));
    int *st_bajtov = malloc(sizeof(int));
    char* ime_datoteke = argv[1];
    unsigned char *pixli = preberi(ime_datoteke, sirina, visina, st_bajtov);
    int rez = sivina(pixli, *sirina, *visina, 1, 1);

    printf("Sirina: %d, Visina: %d, St. bajtov: %d\n", *sirina, *visina, *st_bajtov);
    printf("Sivina: %d\n", rez);

    return 0;
}