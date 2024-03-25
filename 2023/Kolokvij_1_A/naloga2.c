#include <stdio.h>
#include <stdlib.h>

char** poStolpcih(char** nizi, int stVhodnih, int* stIzhodnih) {
    int max = 0;

    for (int i = 0; i < stVhodnih; i++) {
        int len = strlen(nizi[i]);
        if (len > max) {
            max = len;
        }
    }

    char** nova = calloc(max, sizeof(char*));
    for (int i = 0; i < max; i++) {
        nova[i] = calloc(stVhodnih, sizeof(char));
    }

    for (int y = 0; y < max; y++) {
        int p = 0;
        for (int x = 0; x < stVhodnih; x++) {
            if (strlen(nizi[x]) <= y) {
                p++;
                continue;
            }
            nova[y][x-p] = nizi[x][y]; 
        }
    }

    *stIzhodnih = max;

    return nova;
}

char* NIZI[] = {
    "Danes",
    "je",
    "kolokvij",
    "pri_P2!",
};

int main() {
    int stIzhodnih = 0;
    char** rezultat = poStolpcih(NIZI, sizeof(NIZI) / sizeof(NIZI[0]), &stIzhodnih);
    printf("%d\n", stIzhodnih);

    for (int i = 0; i < stIzhodnih; i++) {
        printf("%s\n", rezultat[i]);
        free(rezultat[i]);
    }
    free(rezultat);

    return 0;
}
