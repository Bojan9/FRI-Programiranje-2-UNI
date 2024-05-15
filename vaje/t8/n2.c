#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int memo[500][500][500];

int rek(int* prostor, int* cena, int v, int n, int index, int k, int k_count) {
    if (index == n) {
        return 0;
    }

    if (memo[index][k_count][v] > 0) {
        return memo[index][k_count][v];
    }

    int maxPrice = rek(prostor, cena, v, n, index + 1, k, k_count);

    if (prostor[index] <= v) {
        int newOddVolumeCount = k_count + (prostor[index] % 2 != 0);
        if (newOddVolumeCount <= k) {
            int price = cena[index] + rek(prostor, cena, v - prostor[index], n, index + 1, k, newOddVolumeCount);

            if (price > maxPrice) {
                maxPrice = price;
            }
        }
    }

    memo[index][k_count][v] = maxPrice;

    return maxPrice;
}

int main() {
    int v, n, k;
    
    scanf("%d", &v);
    scanf("%d", &n);
    scanf("%d", &k);

    int* prostor = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &prostor[i]);
    }

    int* cena = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &cena[i]);
    }

    printf("%d", rek(prostor, cena, v, n, 0, k, 0));

    free(prostor);
    free(cena);
    
    return 0;
}