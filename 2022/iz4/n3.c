#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void rek(int d, int n, char* niza, char* zbor, int* znaci, int c) {
    if (c == n) {
        int nema = 0;
        for (int i = 0; i < 126; i++) {
            if (znaci[i] > 3) {
                nema = 1;
                break;
            }
        }
        if (nema == 0) {
            printf("%s\n", zbor);
        }
        return;
    }

    for (int i = 0; i < d; i++) {
        zbor[c] = niza[i];

        znaci[niza[i] - '0']++;

        rek(d, n, niza, zbor, znaci, c + 1);

        znaci[niza[i] - '0']--;
    }
}

int main() {
    int d, n;

    scanf("%d", &d);

    char* niza = malloc(d * sizeof(char));

    scanf("%s", niza);
    scanf("%d", &n);

    char* zbor = calloc(n, sizeof(char));

    int* znaci = calloc(126, sizeof(int));

    rek(d, n, niza, zbor, znaci, 0);

    return 0;
}