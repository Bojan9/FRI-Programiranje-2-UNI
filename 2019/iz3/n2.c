#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n;
    char znak;
    int visina = 0;
    int max_visina = 0;

    scanf("%d", &n);
    scanf("%c", &znak);

    char* niza = (char*)malloc(n * sizeof(char));

    for (int i = 0; i < n; i++) {
        scanf("%c", &znak);
        if (znak == 'G') {
            visina++;
            niza[i] = '/';
        } else {
            visina--;
            niza[i] = '\\';
        }

        if (visina > max_visina)
            max_visina = visina;
    }

    char** printaj = malloc(max_visina * sizeof(char*));

    for (int i = 0; i < max_visina; i++) {
        printaj[i] = malloc(n * sizeof(char));
        for (int j = 0; j < n; j++) {
            printaj[i][j] = '.';
        }
    }

    visina = max_visina - 1;

    for (int i = 0; i < n; i++) {
        printaj[visina][i] = niza[i];
        if (niza[i] == '/' && niza[i+1] != '\\') {
            visina = visina - 1;
        } else if (niza[i] == '\\' && niza[i+1] != '/') {
            visina = visina + 1;
        }
    }

    for (int i = 0; i < max_visina; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", printaj[i][j]);
        }
        printf("\n");
    }

    return 0;
}