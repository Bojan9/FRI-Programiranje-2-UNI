#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
    struct _Vozlisce* n; // naslednje vozlišče v verigi oz. NULL, če ga ni
} Vozlisce;

Vozlisce* sticisce(Vozlisce* a, Vozlisce* b) {
    while (a != NULL) {
        while (b != NULL) {
            if (a->n == b->n) {
                return a->n;
            }
            b = b->n;
        }
        a = a->n;       
    }
    return NULL;
}

int main() {
    return 0;
}