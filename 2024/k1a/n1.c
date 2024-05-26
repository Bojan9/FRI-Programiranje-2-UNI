#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n;

    scanf("%d", &n);

    int* tabela = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &tabela[i]);
    }

    int* nova = calloc(n, sizeof(int));

    int pred = tabela[0];
    int cur_len = 1;
    int gore = 1;
    int y = 0;

    for (int i = 1; i < n; i++) {
        if (gore == 1) {
            if (tabela[i] > pred) {
                cur_len++;
                pred = tabela[i];
            } else {
                nova[y] = cur_len;
                gore = 0;
                cur_len = 2;
                y++;
                pred = tabela[i];
            }
        } else {    
            if (tabela[i] < pred) {
                cur_len++;
                pred = tabela[i];
            } else {
                nova[y] = cur_len;
                gore = 1;
                cur_len = 2;
                y++;
                pred = tabela[i];
            }
        }
    }

    nova[y] = cur_len;

    for (int i = 0; i <= y; i++) {
        printf("%d\n", nova[i]);
    }

    return 0;
}