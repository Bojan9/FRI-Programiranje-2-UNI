
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main(int argc, char** argv) {
    FILE* vlez = fopen(argv[1], "rb");
    FILE* izlez = fopen(argv[2], "wb");

    int c;
    int pred = fgetc(vlez);

    while((c = fgetc(vlez)) != EOF) {
        if (!(pred == 27 && c == 201)) {
            fputc(pred, izlez);
        }
        pred = c;
    }
    fputc(pred, izlez);

    fclose(vlez);
    fclose(izlez);

    return 0;
}
