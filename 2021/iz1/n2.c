#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Vozlisce {
    struct _Vozlisce* n; // naslednje vozlišče v verigi oz. NULL, če ga ni
} Vozlisce;

Vozlisce* sticisce1(Vozlisce* a, Vozlisce* b) {
    Vozlisce* novo_a = a;

    while (novo_a != NULL) {
        Vozlisce* novo_b = b;

        while (novo_b != NULL) {
            if (novo_a->n == novo_b->n) {
                return novo_a->n;
            }
            novo_b = novo_b->n;
        }
        novo_a = novo_a->n;
    }

    return NULL;
}

// Or this (faster)

Vozlisce* sticisce2(Vozlisce* a, Vozlisce* b) {
    Vozlisce* temp = a;

    while (temp->n != NULL) {
        temp = temp->n;
    }

    temp->n = b;

    Vozlisce* slow = a;
    Vozlisce* fast = a;

    while (fast != NULL && fast->n != NULL) {
        slow = slow->n;
        fast = fast->n->n;

        if (fast == slow) {
            break;
        }
    }

    fast = a;

    while (slow != fast) {
        slow = slow->n;
        fast = fast->n;
    }

    return slow;
}

int main() {
    
    return 0;
}