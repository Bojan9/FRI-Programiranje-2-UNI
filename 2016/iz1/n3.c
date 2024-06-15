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

    int* dp = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dp[i] = 1; 
    }

    int naj = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (tabela[j] % tabela[i] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > naj) {
            naj = dp[i];
        }
    }

    printf("%d\n", naj);

    free(tabela);
    free(dp);

    return 0;
}