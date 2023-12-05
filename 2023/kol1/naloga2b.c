#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char** naSredino(char** nizi, int ciljnaDolzina) {
    int cnt = 0;

    for (int i = 0; nizi[i] != NULL; i++) {
        cnt++;
    }

    char** nova = calloc (cnt, sizeof(char*));

    for (int i = 0; i < cnt; i++) {
        char* red = calloc(ciljnaDolzina, sizeof(char));

        int len = strlen(nizi[i]);
        int tocki = ciljnaDolzina - len;
        int levo = tocki/2;
        int desno = tocki/2 + tocki%2;

        for (int j = 0; j < levo; j++) {
            red[j] = '.';
        }

        for (int j = levo; j < len + levo; j++) {
            red[j] = nizi[i][j-levo];
        }

        for (int j = len + levo; j < ciljnaDolzina; j++) {
            red[j] = '.';
        }

        nova[i] = red;
    }    
    return nova;
}

int main() {

    char* NIZI[] = {
    "Danes",
    "je",
    "kolokvij",
    "pri_P2!",
    NULL
};

    char **nova = naSredino(NIZI, 9);

    for (int i = 0; nova[i] != NULL; i++)
    {
        printf("%s\n", nova[i]);
    }

    return 0;
}