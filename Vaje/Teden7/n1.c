#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int c = 0;

void vsota1(int n, int k, int rez, int max_val) {
    if (rez == n) {
        c++;
        return;
    }

    for (int i = 1; i <= k; i++) {
        if (rez + i <= n && i <= max_val) {
            vsota1(n, k, rez + i, i);
        }
    }
}

int vsota2(int n, int k) {
    if (n == 0) {
        return 1;
    }

    if (n < 0 || k == 0) {
        return 0;
    }

    return (vsota2(n-k,k) + vsota2(n,k-1));
} 

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    vsota1(n, k, 0, k);

    printf("%d", c);

    return 0;
}
