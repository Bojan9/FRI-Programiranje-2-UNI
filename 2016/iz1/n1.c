#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int sum(int n) {
    int sum = 0;
    int m;

    while (n > 0) {
        m = n % 10;
        sum = sum + m;
        n = n / 10;
    }

    return sum;
}

void rek(int k, int k_now, int n) {
    if (k == k_now) {
        printf("%d", n);
        return;
    }

    n = sum(n);

    rek(k, k_now + 1, n);
}

int main() {
    int p, q, k;
    scanf("%d %d %d", &p, &q, &k);

    int n = p * q;

    rek(k, 0, n);

    return 0;
}