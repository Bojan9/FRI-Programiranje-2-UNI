#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int steviloZnakov(char* niz, char znak) {
    int c = 0;

    for (int i = 0; niz[i] != '\0'; i++) {
        if (niz[i] == zank) {
            c++;
        }
    }

    return c;
}

char* kopirajDoZnaka(char* niz, char znak) {
    int c = 0;
    
    while(niz[c] != znak && niz[c] != '\0') {
        c++;
    }
    
    char* niza = calloc(c + 1, sizeof(char));

    for (int i = 0; i < c; i++) {
        niza[i] = niz[i];
    }

    return niza;
}

char** razcleni(char* besedilo, char locilo, int* stOdsekov) {
    int c = steviloZnakov(besedilo, locilo) + 1;
    *stOdsekov = c;

    char** niza = calloc(c, sizeof(char*));

    int index = 0;
    int start = 0;

    for (int i = 0; besedilo[i] != '\0'; i++) {
        if (besedilo[i] == locilo) {
            niza[index] = kopirajDoZnaka(besedilo + start, locilo);
            start = i + 1;
            index++;
        }
    }

    niza[index] = kopirajDoZnaka(besedilo + start, '\0');

    return niza;
}

int main() {
    
    return 0;
}