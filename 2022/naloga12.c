#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int agrc, char** argv) {
    FILE* file = fopen(argv[1], "rb");

    int count = 0;
    int b;

    while ((b = fgetc(file)) != EOF) {
        for (int i = 0; i < 8; i++) {
            count += b & 1;
            b = b >> 1;
        }
    }

    printf("%d", count);

    fclose(file);

    return 0;
}