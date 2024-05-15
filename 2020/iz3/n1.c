#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void razlike(FILE* prva, FILE* druga, FILE* izhod) {
    char* niza1 = malloc(1000 * sizeof(char));
    char* niza2 = malloc(1000 * sizeof(char));
    int* tabela = malloc(1000000 * sizeof(int));
    int c = 1;
    int x = 0;

    while(fgets(niza1, 1000, prva) != NULL) {
        fgets(niza2, 1000, druga);

        if (strcmp(niza1, niza2)) {
            tabela[x] = c;
            x++;
        }
        c++;
    }

    for (int i = 0; i < x - 1; i++) {
        fprintf(izhod, "%d\n", tabela[i]);
    } fprintf(izhod, "%d", tabela[x-1]);
}

int main(int argc, char** argv) {
    FILE* prva = fopen(argv[1], "r");
    FILE* druga = fopen(argv[2], "r");
    FILE* izhod = fopen(argv[3], "w");

    razlike(prva, druga, izhod);

    fclose(prva);
    fclose(druga);
    fclose(izhod);

    return 0;
}