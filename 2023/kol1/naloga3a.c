#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int count = 0;

void rek(int n, int m, int momentalna) {
    if (momentalna == n) {
        count++;
    }

    for (int a = 1; a < n; a++) {
        for (int b = m; b <= n; b++) {
            if (a < b) {
                int suma = a * b;
                if (momentalna + suma <= n) {
                    rek(n, m, momentalna + suma);
                }
            }
        }
    }
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    rek(n, m, 0);

    printf("%d", count);

    return 0;
}