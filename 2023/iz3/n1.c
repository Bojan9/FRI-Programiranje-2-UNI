#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* in1 = fopen(argv[1], "rb");
    FILE* in2 = fopen(argv[2], "rb");
    FILE* out = fopen(argv[3], "wb");

    int c1, c2;

    while ((c1 = fgetc(in1)) != EOF && (c2 = fgetc(in2)) != EOF) {
        if (c1 > c2) {
            fputc(c1, out);
        } else {
            fputc(c2, out);
        }
    }

    if (c1 == EOF && c2 != EOF) {
        fputc(c2, out);
        while ((c2 = fgetc(in2)) != EOF) {
            fputc(c2, out);
        }
    }

    if (c1 != EOF && c2 == EOF) {
        fputc(c1, out);
        while ((c1 = fgetc(in1)) != EOF) {
            fputc(c1, out);
        }
    }

    fclose(in1);
    fclose(in2);
    fclose(out);

    return 0;
}