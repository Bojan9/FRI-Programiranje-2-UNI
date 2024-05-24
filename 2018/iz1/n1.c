#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n;

    scanf("%d", &n);

    int* niza = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &niza[i]);
    }

    int vk = 0;
    int naj = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (niza[i] >= naj) {
            vk++;
            naj = niza[i];
        }
    }

    printf("%d", vk);
}