#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* vlez = fopen(argv[1], "rb");
    int prag = atoi(argv[2]);
    FILE* izlez = fopen(argv[3], "wb");

    char niza[100];
    fgets(niza, sizeof(niza), vlez);
    fprintf(izlez, "%s", niza);

    int w, h;
    fscanf(vlez, "%d %d", &w, &h);
    fprintf(izlez, "%d %d\n", w, h);
    fgets(niza, sizeof(niza), vlez); // read new line \n

    fgets(niza, sizeof(niza), vlez);
    fprintf(izlez, "%s", niza);

    unsigned char *pikseli = malloc(w * h * sizeof(unsigned char));
    unsigned char *zapis = malloc(w * h * sizeof(unsigned char));

    fread(pikseli, sizeof(unsigned char), w * h, vlez);

    for (int i = 0; i < w * h; i++) {
        if (pikseli[i] > prag) {
            zapis[i] = 255;
        } else {
            zapis[i] = 0;
        }
    }

    fwrite(zapis, sizeof(unsigned char), w * h, izlez);

    fclose(vlez);
    fclose(izlez);

    return 0;
}