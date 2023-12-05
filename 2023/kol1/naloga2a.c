#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char** poStolpcih(char** nizi, int stVhodnih, int* stIzhodnih) {
    int max = 0;

    for (int i = 0; i < stVhodnih; i++) {
        int len = strlen(nizi[i]);
        if (len > max) {
            max = len;
        }
    }

    char** izhodni = calloc (max, sizeof(char*));
    for (int i = 0; i < max; i++) {
        char* red = calloc (stVhodnih, sizeof(char));
        izhodni[i] = red;
    }

    for (int i = 0; i < max; i++) {
        int count = 0;
        for (int j = 0; j < stVhodnih; j++) {
            if (i >= strlen(nizi[j])) {
                count++;
                continue;
            }

            izhodni[i][j - count] = nizi[j][i];
        }
    }

    *stIzhodnih = max;

    return izhodni;
}

int main() {
    char* vhodniNizi[] = { "Danes", "je", "kolokvij", "pri_P2!" };
    int stVhodnih = sizeof(vhodniNizi) / sizeof(vhodniNizi[0]);

    int stIzhodnih;
    char** izhodniNizi = poStolpcih(vhodniNizi, stVhodnih, &stIzhodnih);

    // Print the output strings
    for (int i = 0; i < stIzhodnih; i++) {
        printf("%s\n", izhodniNizi[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < stIzhodnih; i++) {
        free(izhodniNizi[i]);
    }
    free(izhodniNizi);

    return 0;
}