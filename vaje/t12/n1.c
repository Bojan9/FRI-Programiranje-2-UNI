#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* vlez = fopen(argv[1], "r");
    FILE* izlez = fopen(argv[2], "w");

    char* najgolema = malloc(1000001 * sizeof(char));
    char* sega = malloc(1000001 * sizeof(char));

    int naj = 0;

    while (fgets(sega, 1000001, vlez) != NULL) {
        int dolzina = strlen(sega);

        if (dolzina > naj) {
            naj = dolzina;
            strcpy(najgolema, sega);
        }
    }

    fprintf(izlez, "%s", najgolema);

    free(najgolema);
    free(sega);
    fclose(vlez);
    fclose(izlez);

    return 0;
}