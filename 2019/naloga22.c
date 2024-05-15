#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Oseba Oseba;
struct Oseba { // oseba s podanim imenom in starostjo
    char* ime; // zaporedje do 20 črk angleške abecede
    int starost;
};

void swap(Oseba* prva, Oseba* druga) {
    char* temp_ime = prva->ime;
    int temp_starost = prva->starost;

    prva->ime = druga->ime;
    druga->ime = temp_ime;

    prva->starost = druga->starost;
    druga->starost = temp_starost;
}

void uredi(Oseba** osebe, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(osebe[j]->ime, osebe[j + 1]->ime) > 0) {
                swap(osebe[j], osebe[j + 1]);
            }
        }
    }
}

int main() {
    return 0;
}