#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n; 

    scanf("%d", &n);

    int* niza = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &niza[i]);
    }

    int count = 1;

    for (int i = 0; i < n-1; i++) {
        int najgolem = niza[i];
        for (int j = i+1; j < n; j++) {
            if (niza[j] > najgolem) {
                najgolem = niza[j];
            }
        }
        if (najgolem == niza[i]) {
            count++;
        }
    }

    printf("%d", count);

    free(niza);

    return 0;
}