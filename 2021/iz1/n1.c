#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* vlez = fopen(argv[1], "rb");

    int c = 0;

    while (fgetc(vlez) != EOF) {
        c++;
    }

    if (c == 2) {
        printf("0");
    } else {
        printf("1");
    }

    fclose(vlez);

    return 0;
}