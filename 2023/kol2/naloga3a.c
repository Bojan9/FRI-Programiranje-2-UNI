#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int rastojanie(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

void rek(int n, int k, int* niza, int* krajna, int m, int b) {
    for (int i = 1; i < n; i++) {
        int sega_novo = rastojanie(niza[m * 2], niza[m * 2 + 1], niza[i * 2], niza[i * 2 + 1]);
        int sega_kraj = rastojanie(niza[m * 2], niza[m * 2 + 1], niza[n * 2 - 2], niza[n * 2 - 1]);
        int novo_kraj = rastojanie(niza[i * 2], niza[i * 2 + 1], niza[n * 2 - 2], niza[n * 2 - 1]);
        
        if (novo_kraj < sega_kraj && sega_novo <= k * k) {
            krajna[b++] = i;
            if (novo_kraj == 0) {
                printf("%d", krajna[0]);
                for (int j = 1; j < b; j++) {
                    printf("->%d", krajna[j]);
                }
                printf("\n");
            } else {
                rek(n, k, niza, krajna, i, b);
            }
            b--;
        }
    }
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    int* niza = malloc(n * 2 * sizeof(int));
    int* krajna = malloc(n * sizeof(int));

    krajna[0] = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &niza[i * 2], &niza[i * 2 + 1]);
    }

    rek(n, k, niza, krajna, 0, 1);

    free(niza);
    free(krajna);

    return 0;
}