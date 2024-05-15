#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int rez = 0;

    scanf("%d", &n);

    int* t1 = malloc(n * sizeof(int));
    int* t2 = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &t1[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &t2[i]);
    }

    for (int i = 0; i < n; i++) {
        rez += (t1[i] - t2[i]) * (t1[i] - t2[i]);
    }

    printf("%d", rez);

    free(t1);
    free(t2);

    return 0;
}