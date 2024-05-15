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
        if ((prejsnje == NULL || (strlen(prejsnje->niz) == 0)) && (strlen(p->niz) != 0) && (p->naslednje == NULL || (strlen(p->naslednje->niz) == 0))) {
            char* temp = calloc(1010, sizeof(char));
            strcpy(temp, p->niz);

            char* izpis = calloc(1010, sizeof(char));
            int size = strlen(temp);

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

            p->niz = izpis;
        }
        prejsnje = p;
        p = p->naslednje;
    }
}

Vozlisce* zgradi(char** vrstice, int stVrstic) {
    if (stVrstic == 0) {
        return NULL;
    }
    Vozlisce* zacetek = malloc(sizeof(Vozlisce));
    zacetek->niz = calloc((strlen(*vrstice) + 20), sizeof(char));
    strcpy(zacetek->niz, *vrstice);
    zacetek->naslednje = zgradi(vrstice + 1, stVrstic - 1);
    return zacetek;
}

void pocisti(Vozlisce* zacetek) {
    if (zacetek != NULL) {
        pocisti(zacetek->naslednje);
        free(zacetek->niz);
        free(zacetek);
    }
}

int main() {
    FILE* f = fopen("test01.dat", "r");

    char temp[20];
    fgets(temp, 20, f);
    int stVrstic = atoi(temp);

    char** vrstice = malloc(stVrstic * sizeof(char*));
    char* vrstica = malloc(1010 * sizeof(char));
    for (int i = 0;  i < stVrstic;  i++) {
        fgets(vrstica, 1010, f);
        int dolzina = strlen(vrstica);
        vrstica[dolzina - 1] = '\0';
        vrstice[i] = malloc(dolzina * sizeof(char));
        strcpy(vrstice[i], vrstica);
    }
    fclose(f);
    free(vrstica);

    Vozlisce* zacetek = zgradi(vrstice, stVrstic);
    vstaviH1(zacetek);

    for (Vozlisce* p = zacetek;  p != NULL;  p = p->naslednje) {
        printf("%s\n", p->niz);
    }

    pocisti(zacetek);
    for (int i = 0;  i < stVrstic;  i++) {
        free(vrstice[i]);
    }
    free(vrstice);

    return 0;
}