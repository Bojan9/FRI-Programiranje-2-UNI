#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void count(int n, bool* tabela) {
    int m;

    while (n > 0) {
        m = n % 10;
        tabela[m] = true;
        n = n / 10;
    }
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    bool* tabela = calloc(10, sizeof(bool));
    tabela[0] = true;

    count(a, tabela);
    count(b, tabela);

    int vk = 0;
    for (int i = 0; i < 10; i++) {
        if (tabela[i] == true) {
            vk++;
        }
    }

    printf("%d", vk);

    return 0;
}