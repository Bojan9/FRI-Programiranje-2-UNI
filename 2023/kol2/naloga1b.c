#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* vlez = fopen(argv[1], "r");
    FILE* izlez = fopen(argv[2], "w");

    int c;
    int a = 0;

    while ((c = fgetc(vlez)) != EOF) {

        if (c != ' ' && a == 0) {
            a = 1;
        }

        if (a == 1) {
            fputc(c, izlez);
        }

        if (c == '\n') {
            a = 0;
        }
    }
    
    fclose(vlez);
    fclose(izlez);

    return 0;
}