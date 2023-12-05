#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool izraz() {
    char c;
    scanf("%c", &c);

    if (c == 'T') return true;
    if (c == 'F') return false;
    if (c == '&') return izraz() && izraz();
    if (c == '|') return izraz() || izraz();
    if (c == '!') return !izraz();

    return false;
}

int main() {
    if (izraz() == true) {
        printf("T\n");
    } else {
        printf("F\n");
    }
}