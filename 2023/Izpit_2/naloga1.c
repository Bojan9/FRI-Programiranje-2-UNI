#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* vlez = fopen(argv[1], "rb");
    FILE* izlez = fopen(argv[2], "wb");

    int pred = fgetc(vlez);
    int c;

    while ((c = fgetc(vlez)) != EOF) {
        if (!(pred == c)) {
            fputc(pred, izlez);
        }
        pred = c;
    }

    fputc(pred, izlez);

    fclose(vlez);
    fclose(izlez);

    return 0;
}
