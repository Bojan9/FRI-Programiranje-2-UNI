#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void rek(int n, int nov_n, char* tabela, int count) {
    if (nov_n == 0) {
        for (int i = 0; i < n*2; i++) {
            printf("%c", tabela[i]);
        } printf("\n");
        return;
    }

    for (int i = 0; i < 10; i++) {
        tabela[count] = i + '0';
        if (nov_n != 1) {
            tabela[count + 1] = '+';
            rek(n, nov_n - 1, tabela, count + 2);
            tabela[count + 1] = '-';
            rek(n, nov_n - 1, tabela, count + 2);
        } else {
            rek(n, nov_n - 1, tabela, count + 1);
        }
    }
}

int main() {
    int n;

    scanf("%d", &n);

    char* tabela = malloc((n * 2) * sizeof(char));

    rek(n, n, tabela, 0);

    return 0;
}