#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int rek(int n, int do_n, int visina) {
    if (do_n == n) {
        if (visina == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    int vk = 0;

    if (visina + 1 <= n/2)
        vk += rek(n, do_n + 1, visina + 1);

    if (visina - 1 >= 0)
        vk += rek(n, do_n + 1, visina - 1);
    
    return vk;
}

int main() {
    int n;

    scanf("%d", &n);

    int a = rek(n, 0, 0);

    printf("%d", a);

    return 0;
}