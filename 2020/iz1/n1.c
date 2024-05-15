#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void obrni(FILE* vhod, FILE* izhod) {
    char** tabela = malloc(100 * sizeof(char*));
    char* temp = malloc(100 * sizeof(char));
    int counter = 0;

    while (fgets(temp, 10000, vhod) != NULL) {
        if (counter == 0) {
            temp[strlen(temp) - 1] = '\0';
        }

        tabela[counter] = temp;
        counter++;
        temp = malloc(100 * sizeof(char));
    }

    for (int i = counter - 1; i >= 0; i--) {
        fprintf(izhod, "%s", tabela[i]);
        if (i == counter - 1) {
            fputc('\n', izhod);
        }
    }
}

int main(int argc, char** argv) {
    FILE* vhod = fopen(argv[1], "r");
    FILE* izhod = fopen(argv[2], "w");

    obrni(vhod, izhod);

    fclose(vhod);
    fclose(izhod);

    return 0;
}