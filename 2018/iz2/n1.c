#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n;

    scanf("%d", &n);

    char c;
    int vk = 0;
    int vk_plus = 0;
    int sega = 0;

    for (int i = 0; i < n; i++) {
        scanf("%c", &c);
        if (c == '+' && sega != 0) {
            vk += sega;
            sega = 0;
        }
        if (c == '+' && sega == 0) {
            sega++;
            vk_plus++;
        }
        if (c != '+' && sega != 0) {
            sega++;
        }
    }

    vk_plus--;

    printf("%d ", vk/vk_plus);
}