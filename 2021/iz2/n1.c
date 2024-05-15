#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    char* tabela = malloc(1001 * sizeof(char));  
    scanf("%s", tabela);

    int n = strlen(tabela);
    int ostatok = n % 3;

    if (n <= 3) {
        printf("%s", tabela);
    } else {
        int a;
        if (ostatok == 0) {
            a = 1;
        } else if (ostatok == 1) {
            a = 0;
            printf("%c", tabela[0]);
            printf(".");
        } else if (ostatok == 2) {
            a = -1;
            printf("%c", tabela[0]);
            printf("%c", tabela[1]);
            printf(".");
        }
        for (int i = ostatok; i < n; i++) {
            printf("%c", tabela[i]);
            if ((i + a) % 3 == 0 && i != n-1) {
                printf(".");
            }
        }
    }

    return 0;
}



// ili pak nesto vaka

// int main() {
//     char* tabela = malloc(1001 * sizeof(char));
//     scanf("%s", tabela);
//     int i = strlen(tabela);
//     int start = 0;

//     for (int j = 0; i >= 0; j++) {
//         if (i % 3 == 0 && start == 1 && i != 0) {
//             printf(".");
//         }

//         printf("%c", tabela[j]);

//         start = 1;
//         i--;
//     }
    
//     return 0;
// }