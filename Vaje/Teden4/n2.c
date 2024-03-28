#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n;

    scanf("%d", &n);

    int* tabela = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &tabela[i]);
    }

    int max = -1000;
    int cur = 0;

    for (int i = 0; i < n; i++) {
        cur = cur + tabela[i];

        if (max < cur) {
            max = cur;
        }

        if (cur < 0) {
            cur = 0;
        }
    }

    printf("%d", max);
    
    return 0;
}