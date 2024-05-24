#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* vlez = fopen(argv[1], "r");
    FILE* izlez = fopen(argv[2], "w");
    char a = *(argv[3]);

    char* segasna = malloc(1000 * sizeof(char));
    char* posledna = malloc(1000 * sizeof(char));

    while (fgets(segasna, 1000, vlez)) {
        for (int i = 0; i < strlen(segasna); i++) {
            if (segasna[i] == a) {
                strcpy(posledna, segasna);
            }
        }
    }

    fprintf(izlez, "%s", posledna);

    fclose(vlez);
    fclose(izlez);

    return 0;
}