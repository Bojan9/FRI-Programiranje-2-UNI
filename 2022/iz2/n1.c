#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* vlez = fopen(argv[1], "rb");

    int b;
    int count = 0;

    while ((b = fgetc("vlez")) != EOF) {
        for (int i = 0; i < 8; i++) {
            count += b & 1;
            b = b >> 1;
        }
    }

    printf("%d", count);

    fclose(vlez);

    return 0;
}

// primer eden byte -> 00101100
// prv bit -> 0, vtor -> 0, tret -> 1...
// ako b e prv bit, za da odime kon sleden b >> 1
// b & a -> dvata mora da se 1, za rezultatot da bide 1
// b | a -> eden mora da e 1, za rezultatot da bide 1
// b ^ a -> samo eden mora da e 1, za rezultatot da bide 1

// 10000000
// &
// 00000001
// ---------
// 00000000

// 00000001
// &
// 00000001 (ili 1 samo)
// ---------
// 00000001

// bitni ni se poslednite brojki samo, isto vazi za | i ^

// 10011001 >> 1 -> 01001100
// 11111111 >> 2 -> 00111111
// 11111111 << 2 -> 1111111100