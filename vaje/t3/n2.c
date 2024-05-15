#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100000000000000000LL

long long reverse(long long n) {
    long long rev = 0;

    while (n > 0) {
        int i = n % 10;
        rev = rev * 10 + i;
        n = n / 10;
    }

    return rev;
}

bool palindrom(long long n) {
    return n == reverse(n);
}

int lychrel(long long n, int k) {
    if (palindrom(n)) {
        return 0;
    }

    for (int i = 0; i <= k; i++) {
        n = n + reverse(n);
        if (palindrom(n)) {
            return 0;
        }
        if (n > MAX_LENGTH) {
            return 1;
        }
    }

    return 1;
}

int main() {
    int k, a, b;
    int c = 0;

    scanf("%d %d %d", &k, &a, &b);

    for (int i = a; i <= b; i++) {
        c += lychrel(i, k);
    }

    printf("%d", c);

    return 0;
}