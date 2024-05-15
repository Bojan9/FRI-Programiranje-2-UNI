#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int prvo = 0;
    int vtoro = 0;

    int sega;

    scanf("%d", &n);
    scanf("%d", &prvo);

    for (int i = 1; i < n; i++) {
        scanf("%d", &sega);
        
        if (sega > prvo) {
            vtoro = prvo;
            prvo = sega;
        } else if (sega > vtoro) {
            vtoro = sega;
        }
    }

    printf("%d", vtoro);

    return 0;
}