#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int sestEj(char* niz) {
    int len = strlen(niz);
    int suma = 0;

    for (int i = 0; i < len; i++) {
        if (niz[i] == 'E') {
            if ((niz[i+1] >= '1' && niz[i+1] <= '9') &&
                (niz[i+2] >= '0' && niz[i+2] <= '9') &&
                (niz[i+3] >= '0' && niz[i+3] <= '9') &&
                (niz[i+4] == '_')) {
                    int a = (niz[i+1] - '0') * 100 + (niz[i+2] - '0') * 10 + (niz[i+3] - '0');
                    suma += a;
                    i = i + 5;
                }
        }
    }
    return suma;
}

int main() {
    char niz[] = "543_E123_e456_E75_E900/E7.4_E825.3_E0357_E089_E_EE651_abcdE736_E842";

    printf("%d", sestEj(niz));

    return 0;
}

// ILI VAKA

// int sestEj(char* niz) {
//     int len = strlen(niz);
//     int suma = 0;

//     for (int i = 0; i < len; i++) {
//         while (niz[i] == 'E' && niz[i+1] != '0') {
//             int momentalen = 0;
//             i++;
//             while (niz[i] >= '0' && niz[i] <= '9') {
//                 momentalen = momentalen * 10 + niz[i] - '0';
//                 i++;
//             }
//             if (niz[i] == '_' && momentalen >= 100 && momentalen <= 999) {
//                 suma += momentalen;
//             }
//         }
//     }
//     return suma;
// }