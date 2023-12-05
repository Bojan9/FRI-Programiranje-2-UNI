#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
    char* niz;
    struct _Vozlisce* naslednje;
} Vozlisce;

void vstaviH1(Vozlisce* zacetek) {
    Vozlisce *p = zacetek;
    Vozlisce *prejsnje = NULL;

    while (p != NULL) {
        if ((prejsnje == NULL || (strlen(prejsnje->niz) == 0)) && (p->naslednje == NULL || (strlen(p->naslednje->niz) == 0))) {
            char* temp = calloc(1010, sizeof(char));
            strcpy(temp, p->niz);

            char* izpis = calloc(1010, sizeof(char));
            int size = strlen(temp);

            if (size != 0) {
                for (int i = 0; i < size; i++) {
                    izpis[i + 4] = temp[i];
                }

                izpis[0] = '<';
                izpis[1] = 'h';
                izpis[2] = '1';
                izpis[3] = '>';

                size = size + 4;

                izpis[size] = '<';
                izpis[size + 1] = '/';
                izpis[size + 2]= 'h';
                izpis[size + 3] = '1';
                izpis[size + 4] = '>';
                izpis[size + 5] = '\0';
            }

            p->niz = izpis;
        }
        prejsnje = p;
        p = p->naslednje;
    }
}

int main() {
    return 0;
}