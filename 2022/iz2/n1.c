#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* vlez = fopen(argv[1], "rb");

    int b;
    int count = 0;

    while ((b = fgetc("vlez")) != EOF) {
        for (int i = 0; i < 8; i++) {
            count += b & 1;
            b = b >> 1;
        }
    }

    printf("%d", count);

    fclose(vlez);

    return 0;
}