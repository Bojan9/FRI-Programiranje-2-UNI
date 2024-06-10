#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* input = fopen(argv[1], "rb");
    FILE* output = fopen(argv[2], "wb");

    char* string = malloc (10 * sizeof(char));
    int w, h;

    fgets(string, 10, input);
    fscanf(input, "%d %d", &w, &h);
    fgets(string, 10, input);
    fgets(string, 10, input);

    unsigned char* binary = malloc(3 * w * h * sizeof(unsigned char));
    unsigned char* novi = malloc(w * h * sizeof(unsigned char));

    fread(binary, sizeof(unsigned char), 3 * w * h, input);
    int index = 0;

    for (int i = 0; i < 3 * w * h; i++) {
        novi[index] = (30 * binary[i * 3] + 59 * binary[i * 3 + 1] + 11 * binary[i * 3 + 2]) / 100;
        index++;
    }

    fwrite(novi, sizeof(unsigned char), w * h, output);

    fclose(input);
    fclose(output);

    return 0;
}
