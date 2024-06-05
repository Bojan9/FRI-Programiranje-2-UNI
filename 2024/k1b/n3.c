#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int v, s, k;

    scanf("%d %d %d", &v, &s, &k);

    int* zap_a = malloc(k * sizeof(int));
    int* zap_b = malloc((v + 1) * sizeof(int));
    int* zap_c = malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        scanf("%d", &zap_a[i]);
    }

    for (int i = 0; i < v + 1; i++) {
        scanf("%d", &zap_b[i]);
    }

    for (int i = 0; i < k; i++) {
        scanf("%d", &zap_c[i]);
    }

    int** matrika = malloc(v * sizeof(int*));
    for (int i = 0; i < v; i++) {
        matrika[i] = calloc(s, sizeof(int));
    }

    int vrstica = 0;
    int kol_idx = 0;

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < s; j++) {
            if (j == zap_c[kol_idx] && vrstica < zap_b[i + 1]) {
                matrika[i][j] = zap_a[kol_idx];
                kol_idx++;
                vrstica++;
            }
        }
    }

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < s - 1; j++) {
            printf("%d_", matrika[i][j]);
        } 
        if (i != v - 1) {
            printf("%d\n", matrika[i][s - 1]);
        } else {
            printf("%d", matrika[i][s - 1]);
        }
    }

    return 0;
}