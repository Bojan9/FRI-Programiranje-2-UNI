#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* in = fopen(argv[1], "r");
    FILE* out = fopen(argv[2], "w");

    int pred = fgetc(in);
    int c;

    while ((c = fgetc(in)) != EOF) {
        if (!(pred == '"' && (c == 'C' || c == 'c' || c == 'S' || c == 's' || c == 'Z' || c == 'z'))) {
            fputc(pred, out);
        }
        pred = c;
    }

    fputc(pred, c);

    fclose(in);
    fclose(out);

    return 0;
}