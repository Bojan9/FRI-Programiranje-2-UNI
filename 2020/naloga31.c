#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void razlike(FILE* prva, FILE* druga, FILE* izhod) {
    char** tabela1 = malloc(1000 * sizeof(char*));
    char** tabela2 = malloc(1000 * sizeof(char*));

    char* temp = malloc(1000 * sizeof(char));
    int count = 0;

    while (fgets(temp, 1000, prva) != NULL) {
        tabela1[count] = temp;
        temp = malloc(1000 * sizeof(char));
        count++;
    }

    temp = malloc(1000 * sizeof(char));
    count = 0;

    while (fgets(temp, 1000, druga) != NULL) {
        tabela2[count] = temp;
        temp = malloc(1000 * sizeof(char));
        count++;
    }

    int* tabela_razliki = malloc(count * sizeof(int));
    int razliki = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(tabela1[i], tabela2[i]) != 0) {
            tabela_razliki[razliki] = i+1;
            razliki++;
        }
    }

    for (int i = 0; i < razliki; i++) {
        fprintf(izhod, "%d", tabela_razliki[i]);
        if (i != razliki-1) {
            fprintf(izhod, "\n");
        }
    }
}

int main(int argc, char** argv) {
    FILE* eden = fopen(argv[1], "r");
    FILE* dva = fopen(argv[2], "r");
    FILE* tri = fopen(argv[3], "w");

    razlike(eden, dva, tri);

    return 0;
}