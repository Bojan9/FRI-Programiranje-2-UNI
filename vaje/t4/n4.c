#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n, k;

    scanf("%d%d", &n, &k);

    int* tabela = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &tabela[i]);
    }

    int c = 0;

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (tabela[i] + tabela[j] == k) {
                c++;
            }
        }
    }

    printf("%d", c);
    
    return 0;
}