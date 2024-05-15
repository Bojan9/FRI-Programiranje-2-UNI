#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int rastojanie(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

void rek(int n, int d, int* niza, int* krajna, int index_sega, int index_krajna) {
    for (int i = 1; i < n; i++) {
        int sega_novo = rastojanie(niza[index_sega*2], niza[index_sega*2+1], niza[i*2], niza[i*2+1]);
        int sega_kraj = rastojanie(niza[index_sega*2], niza[index_sega*2+1], niza[n*2-2], niza[n*2-1]);
        int novo_kraj = rastojanie(niza[i*2], niza[i*2+1], niza[n*2-2], niza[n*2-1]);
    
        if (novo_kraj < sega_kraj && sega_novo <= d * d) {
            krajna[index_krajna++] = i;

            if (novo_kraj == 0) {
                printf("%d", krajna[0]);
                for (int j = 1; j < index_krajna; j++) {
                    printf("->%d", krajna[j]);
                }
                printf("\n");
            } else {
                rek(n, d, niza, krajna, i, index_krajna);
            }
            
            index_krajna--;
        }
    }
}

int main() {
    int n;
    int d;

    scanf("%d %d", &n, &d);

    int* niza = malloc(n * 2 * sizeof(int));
    int* krajna = malloc(n * sizeof(int));

    krajna[0] = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &niza[i*2], &niza[i*2+1]);
    }

    rek(n, d, niza, krajna, 0, 1);

    free(niza);
    free(krajna);

    return 0;
}