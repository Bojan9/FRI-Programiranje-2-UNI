#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int stevilo_argumentov() {
    int st1 = 0;
    int st2 = 0;
    int max_st = 0;
    char c;
    int dodaj = 1;

    scanf("%c", &c);
    while (c != ')') {
        if (c == '(') {
            st2 = stevilo_argumentov();
            st2 > max_st ? (max_st = st2) : (max_st = max_st);
        }
        if (dodaj) {
            st1++;
            dodaj = 0;
        }
        scanf("%c", &c);
        if (c == ',') {
            dodaj = 1;
        }
    }
    st1 > max_st ? (max_st = st1) : max_st;
    return max_st;
}

int main() {
    char c;
    int st;

    scanf("%c", &c);
    while (c != '(') {
        scanf("%c", &c);
    }
    st = stevilo_argumentov();
    printf("%d\n", st);

    return 0;
}