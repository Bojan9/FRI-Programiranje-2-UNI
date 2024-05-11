#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* input = fopen(argv[1], "rb");
    FILE* output  = fopen(argv[2], "rwb");

    char* temp = malloc(10 * sizeof(char));

    int width;
    int height;

    fgets(temp, 10, input);
    fscanf(input, "%d %d", &width, &height);
    fgets(temp, 10, input);
    fgets(temp, 10, input);
    
    unsigned char* colors = malloc (3 * width * height * sizeof(unsigned char));
    fread(colors, sizeof(unsigned char), 3 * width * height, input);

    unsigned char* grays = malloc (width * height * sizeof(unsigned char));
    int colorIndex = 0;
    int grayIndex = 0;

    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            grays[grayIndex] = ((30*colors[colorIndex] + 59 * colors[colorIndex+1] + 11 * colors[colorIndex+2]) / 100);
            colorIndex += 3;
            grayIndex++;
        }
    }

    fclose(input);
    fclose(output);

    return 0;
}
