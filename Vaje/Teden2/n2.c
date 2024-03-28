#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;
    int n;
    int pola;

    scanf("%d %d", &a, &b);
    scanf("%d", &n);

    while (n != 0) {
        pola = (a + b) / 2;
    
        if (n == 1) {
            a = pola + 1;
        } else if (n == -1) {
            b = pola - 1;
        }

        scanf("%d", &n);
    }

    if (a == b) {
        printf("%d", a);
    } else if (a < b) {
        printf("%d %d", a, b);
    } else {
        printf("PROTISLOVJE");
    }

    return 0;
}