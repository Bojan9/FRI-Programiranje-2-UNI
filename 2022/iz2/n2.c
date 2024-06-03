#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
    struct _Vozlisce* naslednje;
} Vozlisce;

int dolzinaCikla(Vozlisce* zacetek) {
    Vozlisce *slow = zacetek;
    Vozlisce *fast = zacetek;

    int c = 0;
    bool found = false;

    while (fast && fast->naslednje) {
        slow = slow->naslednje;
        fast = fast->naslednje->naslednje;
        if (found == true) {
            c++;
        }
        if (slow == fast && found == true) {
            return c;
        }
        if (slow == fast && found == false) {
            found = true;
        }
    }

    return c;
}

int main() {

    return 0;
}