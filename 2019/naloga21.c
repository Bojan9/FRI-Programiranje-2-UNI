#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* vhod = fopen(argv[1], "rb");
    int n = atoi(argv[2]);
    FILE* izhod = fopen(argv[3], "w");

    char r, g, b; // Declare as char
    int r_count = 0;
    int g_count = 0;
    int b_count = 0;

    // Read and discard the first line
    char garbage[1000];
    fgets(garbage, sizeof(garbage), vhod);

    int i = 0;
    while (i < n) {
        r = fgetc(vhod);
        g = fgetc(vhod);
        b = fgetc(vhod);

        if (r > 0 && g == 0 && b == 0) {
            r_count++;
        } 
        
        if (r == 0 && g > 0 && b == 0) {
            g_count++;
        } 
        
        if (r == 0 && g == 0 && b > 0) {
            b_count++;
        }

        i++;
    }

    fprintf(izhod, "%d\n", r_count);
    fprintf(izhod, "%d\n", g_count);
    fprintf(izhod, "%d\n", b_count);

    fclose(vhod);
    fclose(izhod);

    return 0;
}