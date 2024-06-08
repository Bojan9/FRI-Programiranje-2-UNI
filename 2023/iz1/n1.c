#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* in = fopen(argv[1], "rb");
    FILE* out = fopen(argv[2], "wb");

    int pred = fgetc(in);
    int c;

    while ((c = fgetc(in)) != EOF) {
        if (!(pred == 27 && c == 201)) {
            fputc(pred, out);
        }
        pred = c;
    }

    fputc(pred, c);

    fclose(in);
    fclose(out);

    return 0;
}