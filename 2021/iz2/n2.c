#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    FILE* vlez = fopen(argv[1], "rb");

    int b;
    int broj = 0;
    int nuli = 0;

    while ((b = fgetc(vlez)) != EOF) {
        if (nuli == 1) {
            broj = (broj << 7) | (b >> 1);
        } else {
            broj = b >> 1;
        }

        nuli = b & 1;

        if (nuli == 0) {
            printf("%d", broj);
        }
    }

    fclose(vlez);

    return 0;
}