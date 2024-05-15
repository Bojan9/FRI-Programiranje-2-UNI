#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void odstraniDuplikate(FILE* vhod, FILE* izhod) {
    int pred = fgetc(vhod);
    int c;

    while ((c = fgetc(vhod)) != EOF) {
        if (c != pred || (c >= '0' && c <= '9')) {
            fputc(pred, izhod);
        }
        pred = c;
    }

    fputc(pred, izhod);
}

int main(int argc, char** argv) {
    FILE* vhod = fopen(argv[1], "r");
    FILE* izhod = fopen(argv[2], "w");

    odstraniDuplikate(vhod, izhod);

    fclose(vhod);
    fclose(izhod);

    return 0;
}