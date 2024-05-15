#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int indexOfMin(int* block, int stDatotek) {
    int min = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < stDatotek; i++) {
        if (block[i] == -1) {
            continue;
        } else {
            if (block[i] < min) {
                min = block[i];
                minIndex = i;
            }
        }
    }

    return minIndex;
}

int main() {
    int stDatotek;
    scanf("%d", &stDatotek);

    char* imeDatoteke = malloc ((101) * sizeof(char));
    FILE** inputs = malloc (stDatotek * sizeof(FILE*));

    for (int i = 0; i < stDatotek; i++) {
        scanf("%s", imeDatoteke);
        inputs[i] = fopen(imeDatoteke, "r");
    } 

    scanf("%s", imeDatoteke);
    FILE* output = fopen(imeDatoteke, "w");

    int finishedFiles = 0;

    int* block = malloc (stDatotek * sizeof(int));

    for (int i = 0; i < stDatotek; i++) {
        if (fscanf(inputs[i], "%d", &block[i]) < 1){
            block[i]= -1;
            finishedFiles++;
        }
    }

    while (finishedFiles < stDatotek) {
        int indexMin = indexOfMin(block, stDatotek);
        fprintf(output, "%d\n", block[indexMin]);

        if (fscanf(inputs[indexMin], "%d", &block[indexMin]) < 1){
            block[indexMin] = -1;
            finishedFiles++;
        }
    }

    for (int i=0; i<stDatotek; i++){
        fclose(inputs[i]);
    }

    fclose(output);

    free(block);
    free (imeDatoteke);
    free (inputs);

    return 0;
}