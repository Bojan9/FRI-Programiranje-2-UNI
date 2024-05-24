#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void podmnozice(int n, int* tabela, int poz, int len, int* pod_mn) {
    if (poz == n) {
        printf("{");
        for (int i = 0; i < len - 1; i++) {
            printf("%d, ", pod_mn[i]);
        }
        if (len != 0) {
            printf("%d", pod_mn[len - 1]);
        }
        printf("}\n");
        return;
    }

    pod_mn[len] = tabela[poz];

    podmnozice(n, tabela, poz + 1, len + 1, pod_mn);
    podmnozice(n, tabela, poz + 1, len, pod_mn);
}

int main() {
    int n;

    scanf("%d", &n);

    int* tabela = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &tabela[i]);
    }

    int* pod_mn = malloc(n * sizeof(int));

    podmnozice(n, tabela, 0, 0, pod_mn);

    free(tabela);
    free(pod_mn);

    return 0;
}