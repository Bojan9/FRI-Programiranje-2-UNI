#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int vk = 0;

void rek(int n, int m, int suma, bool* niza) {
    if (suma == n) {
        vk++;
    }

    for (int a = 2; a < m; a++) {
        if (!niza[a]) {
            for (int b = 1; a + b <= m; b++) {
                if (!niza[b]) {
                    if (suma * (a + b) <= n && (a > b)) {
                        niza[a] = niza[b] = true;
                        rek(n, m, suma * (a + b), niza);
                        niza[a] = niza[b] = false;
                    }
                }
            }
        }
        
    }
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    bool* niza = calloc(n, sizeof(bool));

    rek(n, m, 1, niza);
    printf("%d", vk);

    free(niza);

    return 0;
}