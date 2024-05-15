#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void rek(int n, int a, int b, int* tabela, int idx, int rez, int pred) {
    if (rez == n && idx >= a && idx <= b) {
        for (int i = 0; i < idx - 1; i++) {
            printf("%d+", tabela[i]);
        } printf("%d\n", tabela[idx-1]);
    }

    for (int i = 1; i <= n; i++) {
        if (rez + i <= n && i >= pred) {
            tabela[idx] = i;
            rek(n, a, b, tabela, idx + 1, rez + i, i);
        }
    }
}

int main() {
    int n, a, b;

    scanf("%d %d %d", &n, &a, &b);

    int* tabela = malloc(n * sizeof(int));

    rek(n, a, b, tabela, 0, 0, 0);

    return 0;
}