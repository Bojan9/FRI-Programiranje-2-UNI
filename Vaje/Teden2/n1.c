#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    int c = 0;

    scanf("%d %d", &m, &n);

    for (int i = m; i <= n; i++) {
        for (int a = 1; a < i; a++) {
            for (int b = a; b < i; b++) {
                if ((i * i) == ((a * a) + (b * b))) {
                    c++;
                }
            }
        }
    }

    printf("%d", c);

    return 0;
}
