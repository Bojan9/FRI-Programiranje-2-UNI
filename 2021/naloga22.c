#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* vhod = fopen(argv[1], "rb");

    int b;
    int broj = 0;
    int nuli = 0;

    while ((b = fgetc(vhod)) != EOF) {
        if (nuli) {
            broj = broj << 7 | (b >> 1);
        } else {
            broj = b >> 1;
        }

        nuli = b & 1;

        if (!nuli) {
            printf("%d", broj);
        }
    }
    
    fclose(vhod);

    return 0;
}