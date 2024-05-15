#include <stdio.h>
#include <stdlib.h>

char** naSredino(char** nizi, int ciljnaDolzina) {
    int len = 0;

    for (len = 0; nizi[len] != NULL; len++) {}

    char** nova = calloc(len + 1, sizeof(char*));

    for (int i = 0; i < len; i++) {
        nova[i] = calloc(ciljnaDolzina, sizeof(char));
    }

    for (int i = 0; i < len; i++) {
        int zbor = strlen(nizi[i]);
        int tocki = ciljnaDolzina - zbor;
        int levo = tocki / 2;
        int desno = tocki / 2 + tocki % 2;

        for (int j = 0; j < levo; j++) {
            nova[i][j] = '.';
        }

        for (int j = 0; j < zbor; j++) {
            nova[i][j + levo] = nizi[i][j];
        }

        for (int j = 0; j < desno; j++) {
            nova[i][j + levo + zbor] = '.';
        }
    }

    nova[len] = NULL;

    return nova;
}

char* NIZI[] = {
    "Danes",
    "je",
    "kolokvij",
    "pri_P2!",
    NULL
};

int main() {
    char** izhodni = naSredino(NIZI, 9);

    int stNizov = sizeof(NIZI) / sizeof(NIZI[0]) - 1;
    for (int i = 0; i < stNizov; i++) {
        printf("%d: \"%s\"\n", i, izhodni[i]);
        free(izhodni[i]);
    }
    printf("%s\n", (izhodni[stNizov] == NULL) ? ("NULL") : ("NAPAKA"));

    free(izhodni);
    return 0;
}