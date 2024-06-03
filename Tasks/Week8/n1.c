#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int memo[1001][1001];

int rek(int* prostor, int* cena, int v, int n, int index) {
    if (index == n) {
        return 0;
    }

    if (memo[index][v] > 0) {
        return memo[index][v];
    }

    int maxPrice = rek(prostor, cena, v, n, index + 1);

    if (prostor[index] <= v) {
        int price = cena[index] + rek(prostor, cena, v - prostor[index], n, index + 1);

        if (price > maxPrice) {
            maxPrice = price;
        }
    }

    memo[index][v] = maxPrice;

    return maxPrice;
}

int main() {
    int v, n;
    
    scanf("%d", &v);
    scanf("%d", &n);

    int* prostor = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &prostor[i]);
    }

    int* cena = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &cena[i]);
    }

    printf("%d", rek(prostor, cena, v, n, 0));

    free(prostor);
    free(cena);
    
    return 0;
}
