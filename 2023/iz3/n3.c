#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char najgolem(char* niza, int n) {
    char naj = niza[0];

    for (int i = 0; i < n; i++) {
        if (niza[i] > naj) {
            naj = niza[i];
        }
    }

    return naj;
}

void rek(char* niza, int n) {
    if (n == 0) {
        return;
    }

    if (n == 1) {
        printf("%c\n", niz[0]);
        return;
    }

    if (n > 1) {

    }
}

int main() {
    char* niza = malloc(201 * sizeof(char));

    scanf("%s", &niza);

    int n = strlen(niza);

    return 0;
}