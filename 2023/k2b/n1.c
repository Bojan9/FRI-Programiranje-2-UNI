#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* in = fopen(argv[1], "r");
    FILE* out = fopen(argv[2], "w");

    int c;
    bool flag = false;

    while ((c = fgetc(in) != EOF)) {
        if (c != ' ') {
            fputc(c, out);
            flag = true;
        }
        if (c == ' ' && flag == true) {
            fputc(c, out);
        } 
        if (c == '\n') {
            flag = false;
        }
    }

    fclose(in);
    fclose(out);

    return 0;
}