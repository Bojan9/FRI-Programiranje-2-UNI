#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n;
    char c;

    scanf("%d ", &n);

    char* niza = malloc(n * sizeof(char));

    for (int i = 0; i < n; i++) {
        scanf("%c", &c);
        niza[i] = c;
    }

    for (int i = 0; i < n; i++) {
        if ((niza[i] >= 'a' && niza[i] <= 'z') && (i == 0 || niza[i-1] == '_')) {
            niza[i] = niza[i] - 32;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%c", niza[i]);
    }

    free(niza);

    return 0;
}