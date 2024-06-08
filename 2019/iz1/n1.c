#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* in = fopen(argv[1], "r");
    FILE* out = fopen(argv[2], "w");
    char a = *(argv[3]);

    char* now = malloc(1000 * sizeof(char));
    char* last = malloc(1000 * sizeof(char));

    while (fgets(now, 1000, in)) {
        for (int i = 0; i < strlen(now); i++) {
            if (now[i] == a) {
                strcpy(last, now);
            }
        }
    }

    fprintf(out, "%s", last);

    fclose(in);
    fclose(out);

    return 0;
}