#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* zdruzi(char** nizi, char* locilo) {
    int c = 0;
    int i = 0;
    int z = 0;

    for (i = 0; nizi[i] != NULL; i++) {
        for (int j = 0; nizi[i][j] != '\0'; j++) {
            c++;
        }
    }

    while (locilo[z] != '\0') {
        z++;
    }

    int locila = i - 1;
    c = c + (locila * z);

    char* niza = calloc(c, sizeof(char));

    int indeks = 0;

    for (i = 0; nizi[i] != NULL; i++) {
        for (int j = 0; nizi[i][j] != '\0'; j++) {
            niza[indeks] = nizi[i][j];
            indeks++;
        }
        if (i != locila) {
            for (int j = 0; locilo[j] != '\0'; j++) {
                niza[indeks] = locilo[j];
                indeks++;
            }
        }
    }

    return niza;
}

char* NIZI[] = {"C", "java", "python", "pascal", "javascript", "PHP", NULL};

int main() {
    char* niz = zdruzi(NIZI, "");
    printf("<%s>\n", niz);

    return 0;
}
