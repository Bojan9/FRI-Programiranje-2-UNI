#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* vlez = fopen(argv[1], "r");
    FILE* izlez = fopen(argv[2], "w");

    int c;
    int p = 0;

    while ((c = fgetc(vlez)) != EOF) {
        if (c != ' ') {
            p = 1;
        }

        if (p == 1) {
            fputc(c, izlez);
        }

        if (c == '\n') {
            p = 0;
        }
    }

    fclose(vlez);
    fclose(izlez);

    return 0;
}