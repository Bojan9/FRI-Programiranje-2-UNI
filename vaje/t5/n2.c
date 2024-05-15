#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int* poisci(int* t, int* dolzina, int** konec) {
    int* left = t;
    int* right = t;
    int count = 0;

    while (*(left - 1) != 0) {
        left--;
        count++;
    }

    while (*(right + 1) != 0) {
        right++;
        count++;
    }

    count++;

    *dolzina = count;
    *konec = right;

    return left;
}

int main() {
    int tabela[] = {0, 3, 5, 2, 7, 1, -6, -4, 7, 2, -6, 9, -9, 0};
    int n = 0;
    int* pk = NULL;
    int* pz = poisci(tabela + 12, &n, &pk);
    printf("n = %d, *pz = %d, *pk = %d\n", n, *pz, *pk);

    return 0;
}
