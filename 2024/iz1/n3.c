#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void hanoi(int kolut, char from, char to, char via, int min) {
    static long move = 0;

    if (kolut == 0)
        return;

    hanoi(kolut - 1, from, via, to, min);

    move++;

    if (kolut == 1 && to == 'B' && move > min) {
        printf("%ld\n", move);
    }

    hanoi(kolut - 1, via, to, from, min);
}

int main() {
    int st_kolutov;
    int to_ignore;

    scanf("%d%d", &st_kolutov, &to_ignore);

    hanoi(st_kolutov, 'A', 'C', 'B', to_ignore);

    return 0;
}