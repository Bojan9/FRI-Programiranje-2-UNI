#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXFON 31

typedef struct {
    char* ime;
    char telefon[MAXFON]; // telefonska številka
} Oseba;

void vstaviPredpono(char* predpona, Oseba** osebe, int stOseb) {
    for (int i = 0; i < stOseb; i++) {
        char* temp = calloc(31, sizeof(char));
        strcpy(temp, osebe[i]->telefon);

        int p = strlen(predpona);
        int s = strlen(osebe[i]->telefon);


        for (int j = 0; j < p; j++) {
            osebe[i]->telefon[j] = predpona[j];
        }

        for (int j = p; j < p + s; j++) {
            osebe[i]->telefon[j] = temp[j-p];
        }
    }
}

int main() {
    FILE* f = fopen("test01.dat", "r");
    int stOseb = 0;
    fscanf(f, "%d", &stOseb);

    char ime[100] = {'\0'};
    char predpona[100] = {'\0'};

    Oseba** osebe = malloc(stOseb * sizeof(Oseba*));
    for (int i = 0;  i < stOseb;  i++) {
        Oseba* oseba = calloc(1, sizeof(Oseba));
        fscanf(f, "%s%s", ime, oseba->telefon);
        oseba->ime = calloc(strlen(ime) + 1, sizeof(char));
        strcpy(oseba->ime, ime);
        osebe[i] = oseba;
    }
    fscanf(f, "%s", predpona);
    fclose(f);

    vstaviPredpono(predpona, osebe, stOseb);

    for (int i = 0;  i < stOseb;  i++) {
        printf("%s / %s\n", osebe[i]->ime, osebe[i]->telefon);
    }

    for (int i = 0;  i < stOseb;  i++) {
        free(osebe[i]->ime);
        free(osebe[i]);
    }
    free(osebe);
    return 0;
}
