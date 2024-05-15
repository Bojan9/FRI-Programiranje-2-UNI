#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int rek(int n, int k) {
    if (k < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }

    int vk = 0;

    // ako stavime 1
    vk += rek(n - 1, k + 1);

    // ako stavime 2
    vk += rek(n - 1, k - 1);

    return vk;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    int a = rek(n, k);

    printf("%d", a);

    return 0;
}