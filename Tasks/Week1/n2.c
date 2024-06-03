#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int prvo;
    int sledno;
    int rez = 1;

    scanf("%d", &n);
    scanf("%d", &prvo);

    for (int i = 1; i < n; i++) {
        scanf("%d", &sledno);
        if (prvo != sledno) {
            rez = 0;
        }
    }

    printf("%d", rez);

    return 0;
}