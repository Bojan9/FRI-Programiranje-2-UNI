#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    FILE* vlez = fopen(argv[1], "rb");
    int n = atoi(argv[2]);
    FILE* izlez = fopen(argv[3], "w");

    int r_count = 0;
    int g_count = 0;
    int b_count = 0;

    int r, g, b;

    // Read and discard the first line
    char garbage[1000];
    fgets(garbage, sizeof(garbage), vhod);

    for (int i = 0; i < n; i++) {
        r = fgetc(vlez);
        g = fgetc(vlez);
        b = fgetc(vlez);

        if (r > 0 && g == 0 && b == 0) {
            r_count++;
        }

        if (r == 0 && g > 0 && b == 0) {
            g_count++;
        }

        if (r == 0 && g == 0 && b > 0) {
            b_count++;
        }
    }

    fprintf("%d\n", r_count);
    fprintf("%d\n", g_count);
    fprintf("%d", b_count);

    fclose(vlez);
    fclose(izlez);

    return 0;
}