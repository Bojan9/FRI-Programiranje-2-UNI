#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* vlez = fopen(argv[1], "r");
    FILE* izlez = fopen(argv[2], "w");

    int c;
    int nov_red = 1;

    while ((c = fgetc(vlez)) != EOF) {
        if (c != ' ') {
            fputc(c, izlez);
            nov_red = 0;
        }

        if (c == ' ' && nov_red == 0) {
            fputc(c, izlez);
        }

        if (c == '\n') {
            nov_red = 1;
        }
    }

    fclose(vlez);
    fclose(izlez);

    return 0;
}