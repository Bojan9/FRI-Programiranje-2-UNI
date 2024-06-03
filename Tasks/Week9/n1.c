#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void rek(int n, char c1, char c2, char* tabela, int index) {
    if (index > 0) {
        printf("%s\n", tabela);
    }

    if (index >= n) {
        return;
    }

    for (char i = c1; i <= c2; i++) {
        tabela[index] = i;
        rek(n, c1, c2, tabela, index + 1);
        tabela[index] = '\0';
    }
}

int main() {
    int n;
    char c1, c2;
    
    scanf("%d", &n);
    scanf(" %c", &c1);
    scanf(" %c", &c2);

    char* tabela = calloc(n, sizeof(int));

    rek(n, c1, c2, tabela, 0);

    free(tabela);
    
    return 0;
}
