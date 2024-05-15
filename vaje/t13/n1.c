#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* input = fopen(argv[1], "rb");

    int vrstica = atoi(argv[2]);
    int stolpec = atoi(argv[3]);

    char* string = malloc (10 * sizeof(char));

    fgets(string, 10, input);

    int w, h;
    fscanf(input, "%d %d", &w, &h);

    fgets(string, 10, input);
    fgets(string, 10, input);

    unsigned char* binary = malloc(3 * w * h * sizeof(unsigned char));

    fread(binary, sizeof(unsigned char), 3  * w * h, input);

    int index = 3 * (vrstica * w + stolpec);
    printf("%d %d %d", binary[index], binary[index+1], binary[index+2]);

    fclose(input);

    return 0;
}