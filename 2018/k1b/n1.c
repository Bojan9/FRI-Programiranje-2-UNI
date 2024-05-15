#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int m, n;

    scanf("%d", &m);

    int* niza1 = calloc(m, sizeof(int));

    for (int i = 0; i < m; i++) {
        scanf("%d", &niza1[i]);
    }

    scanf("%d", &n);

    int* niza2 = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &niza2[i]);
    }

    int* nova = calloc(m + n, sizeof(int));

    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (niza1[i] < niza2[j]) {
            if (k == 0) {
                nova[k++] = niza1[i++];
                continue;
            }

            if (nova[k-1] == niza1[i]) {
                i++;
            } else {
                nova[k++] = niza1[i++];
            }

        } else if (niza1[i] > niza2[j]) {
            if (k == 0) {
                nova[k++] = niza2[j++];
                continue;
            }

            if (nova[k-1] == niza2[j]) {
                j++;
            } else {
                nova[k++] = niza2[j++];
            }

        } else {
            if (k == 0) {
                nova[k++] = niza2[j++];
                i++;
                continue;
            }

            if (nova[k-1] == niza2[j]) {
                i++;
                j++;
            } else {
                nova[k++] = niza2[j++];
                i++;
            }
        }
    }

    while (i < m) {
        if (k == 0) {
            nova[k++] = niza1[i++];
            continue;
        }

        if (nova[k-1] == niza1[i]) {
            i++;
        } else {
            nova[k++] = niza1[i++];
        }
    }

    while (j < n) {
        if (k == 0) {
            nova[k++] = niza2[j++];
            continue;
        }

        if (nova[k-1] == niza2[j]) {
            j++;
        } else {
            nova[k++] = niza2[j++];
        }
    }

    for (int z = 0; z < k; z++) {
        printf("%d\n", nova[z]);
    }
    

    return 0;
}