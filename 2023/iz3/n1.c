#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* vlez1 = fopen(argv[1], "rb");
    FILE* vlez2 = fopen(argv[2], "rb");
    FILE* izlez = fopen(argv[3], "wb");

    int c1;
    int c2;

    while ((c1 = fgetc(vlez1)) != EOF && (c2 = fgetc(vlez2)) != EOF) {
        if (c1 > c2) {
            fputc(c1, izlez);
        } else {
            fputc(c2, izlez);
        }
    }

    if (c1 == EOF && c2 != EOF) {
        while ((c2 = fgetc(vlez2)) != EOF) {
            fputc(c2, izlez);
        }
    }

    if (c1 != EOF && c2 == EOF) {
        fputc(c1, izlez);
        while ((c1 = fgetc(vlez1)) != EOF) {
            fputc(c1, izlez);
        }
    }

    fclose(vlez1);
    fclose(vlez2);
    fclose(izlez);

    return 0;
}