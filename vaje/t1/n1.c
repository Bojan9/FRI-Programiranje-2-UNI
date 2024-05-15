#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    int rez = (a + b) % 10;

    printf("%d", rez);

    return 0;
}