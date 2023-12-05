#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n;
    char c;

    scanf("%d ", &n);

    char* niza = malloc(n * sizeof(char));
    
    for (int i = 0; i < n; i++) {
        scanf("%c", &c);
        niza[i] = c;
    }

    int vk_rez = 0;
    int vk_plus = 0;

    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (niza[i] == '+' && niza[j] == '+') {                
                vk_rez += j - i;
                i = j - 1;
                vk_plus++;
            }
        }   
    }

    if (vk_plus != 0) {
        vk_rez = vk_rez / vk_plus;
    }    

    printf("%d", vk_rez);

    free(niza);

    return 0;
}