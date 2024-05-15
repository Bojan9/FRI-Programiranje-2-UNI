#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void podmnozice(int n, int *stevila, int poz, int len, int *pod) {
    if (poz == n) {
        printf("{");
        for (int i = 0; i < len - 1; i++) {
            printf("%d, ", pod[i]);
        }
        if (len != 0) {
            printf("%d", pod[len - 1]);
        }
        printf("}\n");
        return;
    }
    pod[len] = stevila[poz];
    podmnozice(n, stevila, poz + 1, len + 1, pod);
    podmnozice(n, stevila, poz + 1, len, pod);
}

int main() {
    int n;

    scanf("%d", &n);

    int* tabela = malloc(n * sizeof(int));
    int* pod = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &tabela[i]);
    }

    podmnozice(n, tabela, 0, 0, pod);

    free(tabela);
    free(pod);

    return 0;
}