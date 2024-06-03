#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void rek(char** niza_p, char* niza_s, int k, int n, int indeks) {
    if (k == n) {
        printf("%s\n", niza_s);
        return;
    }

    for (int i = 0; niza_p[k][i] != '\0'; i++) {
        niza_s[indeks] = niza_p[k][i];
        rek(niza_p, niza_s, k + 1, n, indeks + 1);
    }
}

int main() {
    int n;

    scanf("%d", &n);

    char** niza = calloc(n, sizeof(char*));

    for (int i = 0; i < n; i++) {
        niza[i] = calloc(42, sizeof(char));
        scanf("%s", niza[i]);
    }

    char* niza_s = calloc(n, sizeof(char));

    rek(niza, niza_s, 0, n, 0);

    return 0;
}
