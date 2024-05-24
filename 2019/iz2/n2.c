#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Oseba Oseba;

struct Oseba { // oseba s podanim imenom in starostjo
    char* ime; // zaporedje do 20 črk angleške abecede
    int starost;
};

void uredi(Oseba** osebe, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(osebe[i]->ime, osebe[j]->ime) > 0) {
                char* temp_ime = osebe[i]->ime;
                int temp_starost = osebe[i]->starost;

                osebe[i]->ime = osebe[j]->ime;
                osebe[j]->ime = temp_ime;

                osebe[i]->starost = osebe[j]->starost;
                osebe[j]->starost = temp_starost;
            }
        }
    }
}

int main() {

    return 0;
}