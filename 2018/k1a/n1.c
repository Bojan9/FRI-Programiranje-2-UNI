#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n;

    scanf("%d", &n);

    int* niza = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &niza[i]);
    }

    int d = 0;
    int index = 0;
    int* pamti = malloc(n * sizeof(int));

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (niza[i] == niza[j]) {
                int cur = j - i;
                if (cur > d) {
                    index = 0;
                    d = cur;
                }
                if (cur == d) {
                    pamti[index] = niza[i];
                    index++;
                }
            }
        }
    }

    printf("%d\n", d);

    if (d != 0) {
        for (int i = 0; i < index; i++) {
            printf("%d\n", pamti[i]);
        }
    }
    

    return 0;
}