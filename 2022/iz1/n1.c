#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int sestEj(char* niz) {
    int n = strlen(niz);
    int rez = 0;

    for (int i = 0; i < n; i++) {
        if (niz[i] == 'E') {
            if ((niz[i + 1] >= '1' && niz [i + 1] <= '9') &&
                (niz[i + 2] >= '0' && niz [i + 2] <= '9') &&
                (niz[i + 3] >= '0' && niz [i + 3] <= '9') &&
                (niz[i + 4] == '_')) {
                    rez += (niz[i + 1] - '0') * 100 + (niz[i + 2] - '0') * 10 + (niz[i + 3] - '0');
                    i = i + 5;
                }
        }
    }

    return rez;
}

int main() {
    printf("%d", sestEj("543_E123_e456_E75_E900/E7.4_E825.3_E0357_E089_E_EE651_abcdE736_E842"));

    return 0;
}