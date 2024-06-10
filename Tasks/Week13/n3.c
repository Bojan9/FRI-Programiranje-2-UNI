#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* input = fopen(argv[1], "rb");
    int k = atoi(argv[2]);
    
    int idx = 0;
    int c;

    FILE* output = NULL;
    int chunk_index = 0;
    char output_filename[256];

    while ((c = fgetc(input)) != EOF) {
        if (idx == 0) {
            snprintf(output_filename, sizeof(output_filename), "%s.%d", argv[1], chunk_index);
            output = fopen(output_filename, "wb");
        }

        idx++;
        fputc(c, output);

        if (idx == k) {
            fclose(output);
            idx = 0;
        }
    }

    if (output != NULL) {
        fclose(output);
    }
    fclose(input);

    return 0;
}
