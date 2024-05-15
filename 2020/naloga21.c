#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void odstraniDuplikate(FILE* vhod, FILE* izhod) {
    int c;
    int pred = -1;

    while ((c = fgetc(vhod)) != EOF) {
        if (c == pred) {
            if (c >= '0' && c <= '9') {
                fputc(c, izhod);
            }
            pred = c;
        } else {
            fputc(c, izhod);
            pred = c;
        }
    }
}

int main(int argc, char** argv) {
    FILE* eden = fopen(argv[1], "r");
    FILE* dva = fopen(argv[2], "w");

    odstraniDuplikate(eden, dva);

    return 0;
}