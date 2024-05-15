#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
    struct _Vozlisce* naslednje;
} Vozlisce;

int dolzinaCikla(Vozlisce* zacetek) {
    Vozlisce* tabela = zacetek;
    int c = 0;

    for (int i = 0; i < 1001; i++) {
        tabela[i] = zacetek;
        zacetek = zacetek->naslednje;
    }

    for (int i = 0; i < 1001; i++) {
        for (int j = i + 1; j < 1001; j++) {
            if (tabela[i] == tabela[j]) {
                c = j - i;
                return c;
            }
        }
    }

    return c;
}

// ili vaka

// int dolzinaCikla(Vozlisce* zacetek) {
//     int count = 0;

//     for (int i = 0; i < 1000; i++) {
//         Vozlisce* novo = zacetek->naslednje;
//         for (int j = 0; j < 1000; j++) {
//             if (zacetek->naslednje == novo->naslednje) {
//                 novo = novo->naslednje;
//                 while (!(zacetek->naslednje == novo->naslednje)) {
//                     novo = novo->naslednje;
//                     count++;
//                 }
//                 return count + 1;
//             }
//             novo = novo->naslednje;
//         }
//         zacetek = zacetek->naslednje;
//     }

//     return count;
// }


int main() {

    return 0;
}