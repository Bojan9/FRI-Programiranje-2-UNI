#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int palindrom = 1;
    int rez = 0;

    scanf("%d", &n);

    int* niza = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &niza[i]);
    }

    for (int i = 0; i < n/2; i++) {
        if (niza[i] != niza[n-1-i]) {
            palindrom = 0;
        }
        rez += niza[i] + niza[n-1-i];
    }

    if (n % 2 != 0) {
        rez += niza[n/2];
    }

    if (palindrom == 1) {
        printf("DA\n");
        printf("%d", rez);
    } else {
        printf("NE\n");
        printf("%d", rez);
    }

    free(niza);

    return 0;
}