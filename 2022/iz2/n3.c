#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int znak(int n, int x, int y) {
    if (n == 0) {
        return 1;
    }

    int size = pow(2, n);

    if (x < size / 2 && y >= size / 2) {
        return 0;
    }

    if (x >= size / 2) x = x - size / 2;
    if (y >= size / 2) y = y - size / 2;

    znak(n - 1, x, y);
}

int main() {
    int n, v0, s0, h, w;

    scanf("%d %d %d %d %d", &n, &v0, &s0, &h, &w);

    int c = pow(3, n);

    printf("%d\n", c);

    for (int i = v0; i < v0 + h; i++) {
        for (int j = s0; j < s0 + w; j++) {
            int z = znak(n, j, i);
            if (z == 1) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }

    return 0;
}