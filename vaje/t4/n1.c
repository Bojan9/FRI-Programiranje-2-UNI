#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n, br;

    scanf("%d", &n);

    bool* set = calloc(1000000000, sizeof(bool));

    for (int i = 0; i < n; i++) {
        scanf("%d", &br);
        set[br] = true;
    }

    for (int i = 0; i < n; i++) {
        if (!set[i]) {
            printf("NE");
            return 0;
        }
    }

    printf("DA");
    return 0;
}