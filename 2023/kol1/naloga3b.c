#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int rek(int n, int m, bool* niza) {
    int sum = 0;

    for (int a = n - 1; a > 0; a--) {
        if (!niza[a]) {
            for (int b = a - 1; b > 0; b--) {
                if (!niza[b] && a + b <= m) {
                    sum += (a + b == n);

                    if (n % (a + b) == 0) {
                        niza[a] = niza[b] = true;

                        sum += rek(n / (a + b), m, niza);

                        niza[a] = niza[b] = false;
                    }
                }
            }
        }
    }
    return sum;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    bool* niza = calloc(m + 1, sizeof(bool));

    printf("%d", rek(n, m, niza));

    return 0;
}