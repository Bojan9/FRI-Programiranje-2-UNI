#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int vk = 0;

int rek(int n, int m, int suma) {
    if (suma == n) {
        vk++;
    }

    for (int a = 1; a < m; a++) {
        for (int b = m; b <= n; b++) {
            if (suma + (a * b) <= n && (a < b)) {
                rek(n, m, suma + (a * b));
            }
        }
    }
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    rek(n, m, 0);
    printf("%d", vk);

    return 0;
}