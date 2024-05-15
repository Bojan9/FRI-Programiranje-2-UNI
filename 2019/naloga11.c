#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* vhod = fopen(argv[1], "r");
    FILE* izhod = fopen(argv[2], "w");

    char a = *(argv[3]);

    char* segasna = malloc(1000 * sizeof(char));
    char* posledna = malloc(1000 * sizeof(char));

    while (fgets(segasna, 1000, vhod)) {
        for (int i = 0; i < strlen(segasna); i++) {
            if (segasna[i] == a) {
                strcpy(posledna, segasna);
            }
        }
    }

    fprintf(izhod, "%s", posledna);

    free(segasna);
    free(posledna);

    return 0;
}