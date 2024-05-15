#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Vozlisce Vozlisce;
struct Vozlisce {
    int vrednost;
    Vozlisce* naslednje;
};

Vozlisce* prepisi(int* t) {
    Vozlisce *prvo = malloc(sizeof(struct Vozlisce));
    prvo->naslednje = NULL;
    prvo->vrednost = 0;
    
    // bubble sort
    int counter = 0;
    int *p = t;
    while (*p != 0) {
        p++;
        counter++;
    }

    for (int i = 0; i < counter; i++) {
        for (int j = 0; j < counter; j++) {
            if(t[i] < t[j]) {
                int temp = t[j];
                t[j] = t[i];
                t[i] = temp;
            }
        }
    }

    if (t[0] == 0) {
        return NULL;
    }

    Vozlisce *prejsnje = malloc(sizeof(struct Vozlisce));
    prejsnje = prvo;
    prejsnje->vrednost = t[0];
    int i = 1;

    while (i < counter) {
        Vozlisce *novo = malloc(sizeof(struct Vozlisce));
        prejsnje->naslednje = novo;
        novo->vrednost = t[i];
        prejsnje = novo;
        i++;
    }
    
    return prvo;
}

int main() {
    return 0;
}