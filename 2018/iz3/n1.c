#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n;

    scanf("%d", &n);

    char* niza = calloc(n, sizeof(char));

    int start = 1;
    char c;

    for (int i = 0; i < n; i++) {
        scanf(" %c", &c);

        if (c == '_') {
            start = 1;
        }
        if (c != '_' && start == 1) {
            start = 0;
            if (c >= 'a' && c <= 'z') {
                c = c - 32;
            }
        }
        niza[i] = c;
    }

    printf("%s", niza);

    return 0;
}