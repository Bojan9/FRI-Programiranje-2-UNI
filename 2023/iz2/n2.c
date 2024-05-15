#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void rek(char* niza, int a, int b, bool* znaci, int n, int pozicija, int broj) {
    if (broj > a - 1) {
        for (int i = 0; i < n; i++) {
            printf("%c", niza[i]);

            if (znaci[i]) {
                printf("|");
            }
        } printf("\n");

        if (broj + 1 >= b) {
            return;
        }
    }

    for (int i = pozicija + 1; i < n - 1; i++) {
        znaci[i] = true;
        rek(niza, a, b, znaci, n, i, broj + 1);
        znaci[i] = false;
    }
}

int main() {
    char* niza = malloc(16 * sizeof(char));
    bool* znaci = calloc(16, sizeof(bool));
    int a, b, n;

    scanf("%s %d %d", niza, &a, &b);
    n = strlen(niza);

    rek(niza, a, b, znaci, n, -1, 0);

    free(niza);
    free(znaci);

    return 0;
}