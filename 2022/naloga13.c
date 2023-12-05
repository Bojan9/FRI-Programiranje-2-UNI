#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int agrc, char** argv) {
    FILE* vlez = fopen(argv[1], "rb");
    int prag = atoi(argv[2]);
    FILE* izlez = fopen(argv[3], "wb");

    char smeti[100];
    fgets(smeti, sizeof(smeti), vlez);

    int sirina;
    int visina;

    fscanf(vlez, "%d %d", &sirina, &visina);
    fgets(smeti, sizeof(smeti), vlez);

    unsigned char *pikseli = malloc(sirina * visina * sizeof(unsigned char));
    unsigned char *zapis  = malloc(sirina * visina * sizeof(unsigned char));

    fread(pikseli, sizeof(unsigned char), sirina * visina, vlez);

    for (int i = 0; i < sirina * visina; i++) {
        if (pikseli[i] >= prag) {
            zapis[i] = 255;
        } else {
            zapis[i] = 0;
        }
    }

    fprintf(izlez, "P5\n");
    fprintf(izlez, "%d %d\n", sirina, visina);
    fprintf(izlez, "255\n");

    fwrite(zapis, sizeof(unsigned char), sirina * visina, izlez);

    fclose(vlez);
    fclose(izlez);

    return 0;
}

// fscanf - char/int citaj do space
// fgets - citaj cela linija
// fread - citaj cel fajl (povekje linii)