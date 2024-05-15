#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void rek(int n, char* tabela, int idx) {
    if (idx == n * 2) {
        printf("%s\n", tabela);
        return;
    }

    for (int i = 0; i < 10; i++) {
        tabela[idx] = i + '0';

        if (idx == (n * 2 - 2)) {
            rek(n, tabela, idx + 2);
        } else {
            tabela[idx+1] = '+';
            rek(n, tabela, idx + 2);

            tabela[idx+1] = '-';
            rek(n, tabela, idx + 2);
        }
    }
}

int main() {
    int n;

    scanf("%d", &n);

    char* tabela = calloc(n * 2, sizeof(char));

    rek(n, tabela, 0);

    free(tabela);

    return 0;    
}