#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char* tabela = malloc(1001 * sizeof(char));
    scanf("%s", tabela);
    int i = strlen(tabela);
    int start = 0;

    for (int j = 0; i >= 0; j++) {
        if (i % 3 == 0 && start == 1 && i != 0) {
            printf(".");
        }

        printf("%c", tabela[j]);

        start = 1;
        i--;
    }
    
    return 0;
}