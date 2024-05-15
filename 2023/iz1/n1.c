#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* vlez = fopen(argv[1], "rb");
    FILE* izlez = fopen(argv[2], "wb");

    int c;
    int pred = fgetc(vlez);

    while ((c = fgetc(vlez)) != EOF) {
        if(!(pred == 27 && c == 201)) {
            fputc(pred, izlez);
        }
        pred = c;
    }

    fputc(pred, izlez);

    fclose(vlez);
    fclose(izlez);

    return 0;
}