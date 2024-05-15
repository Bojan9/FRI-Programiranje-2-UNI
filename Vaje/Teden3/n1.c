#include <stdio.h>
#include <stdlib.h>

int deliteli(int n) {
    int rez = 0;

    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            rez += i;
        }
    }

    return rez;
}

int main() {
    int n;

    scanf("%d", &n);

    int friend = deliteli(n);

    if (n == deliteli(friend)) {
        printf("%d", friend);
    } else {
        printf("NIMA");
    }

    return 0;
}
