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

    int a = 0;
    bool flag = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < tabela[i] - 1; j++) {
            printf("%d\n", a);

            if (flag) {
                a++;
            } else {
                a--;
            } 
            
        }

        if (flag) {
            flag = false;
        } else {
            flag = true;
        }
    }

    printf("%d", a);

    return 0;
}