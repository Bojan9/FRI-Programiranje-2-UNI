#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void vsota(int n, int k, int rez, int max_val, int* tabela, int j) {
    if (rez == n) {
        for (int z = 0; z < j-1; z++) {
            printf("%d + ", tabela[z]);
        } printf("%d\n", tabela[j-1]);
        return;
    }

    for (int i = k; i >= 1; i--) {
        if (rez + i <= n && i <= max_val) {
            tabela[j] = i;
            vsota(n, k, rez + i, i, tabela, j + 1);
        }
    }
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    int* tabela = calloc(n, sizeof(int));

    vsota(n, k, 0, k, tabela, 0);

    return 0;
}
