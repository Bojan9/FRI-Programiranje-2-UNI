#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* input = fopen(argv[1], "rb");
    int p = atoi(argv[2]);
    int q = atoi(argv[3]);
    
    int c;
    int bit_index = 0;

    while ((c = fgetc(input)) != EOF) {
        for (int i = 7; i >= 0; i--) {  // Extract bits from the byte
            if (bit_index >= p && bit_index < q) {
                int bit = (c >> i) & 1;
                printf("%d", bit);
            }
            bit_index++;
            if (bit_index >= q) {
                break;
            }
        }
        if (bit_index >= q) {
            break;
        }
    }

    fclose(input);

    return 0;
}
