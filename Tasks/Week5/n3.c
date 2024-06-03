#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void zamenjaj(int** a, int** b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}

void uredi(int** a, int** b, int** c) {
    if (**a > **b) {
        zamenjaj(a, b);
    }
    if (**a > **c) {
        zamenjaj(a, c);
    }
    if (**b > **c) {
        zamenjaj(b, c);
    }
}

int main() {
    int a = 0;
    int b = 1;
    int c = 0;

    int* pa = &a;
    int* pb = &b;
    int* pc = &c;

    uredi(&pa, &pb, &pc);

    printf("*pa = %d, *pb = %d, *pc = %d\n", *pa, *pb, *pc);
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}
