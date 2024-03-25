#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* vlez = fopen(argv[1], "r");
    FILE* izlez = fopen(argv[2], "w");

    int c;
    int pred = fgetc(vlez);

    while ((c = fgetc(vlez)) != EOF) {
        if (!(pred == '"' && (c == 'C' || c == 'c' || c == 'S' || c == 's' || c == 'Z' || c == 'z'))) {
            fputc(pred, izlez);
        } 
        pred = c;
    } 
    
    fputc(pred, izlez);

    fclose(vlez);
    fclose(izlez);

    return 0;
}
