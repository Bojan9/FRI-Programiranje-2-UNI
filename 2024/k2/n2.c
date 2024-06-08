#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int count_lines(FILE* file) {
    int count = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }
    rewind(file);
    return count;
}

int* indeks(char** niza_argv, char** niza_file, int n, int m) {
    int* indeksi = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (strcmp(niza_argv[i], niza_file[j]) == 0) {
                indeksi[i] = j;
            }
        }
    }

    return indeksi;
}

int main(int argc, char** argv) {
    FILE* vlez = fopen(argv[1], "r");
    FILE* izlez = fopen(argv[2], "w");
    int m = atoi(argv[3]);

    int n = argc - 4;

    char** niza_argv = malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        niza_argv[i] = argv[i + 4];
    }

    // Count the number of lines in the input file - 1 (first line).
    int num_lines = count_lines(vlez) - 1;

    // Get first line and match the indexes from the niza_argv
    char** niza_file = malloc(m * sizeof(char*));

    for (int i = 0; i < m; i++) {
        niza_file[i] = malloc(100 * sizeof(char));
        fscanf(vlez, "%s", niza_file[i]);
    }

    int* indeksi = indeks(niza_argv, niza_file, n, m);

    // Print the first line
    for (int i = 0; i < n - 1; i++) {
        fprintf(izlez, "%s,", niza_file[indeksi[i]]);
    }
    fprintf(izlez, "%s\n", niza_file[indeksi[n - 1]]);

    // Get the rest of the lines and print them
    for (int i = 0; i < num_lines; i++) {
        char** niza_line = malloc(m * sizeof(char*));

        for (int j = 0; j < m; j++) {
            niza_line[j] = malloc(100 * sizeof(char));
            fscanf(vlez, "%s", niza_line[j]);
        }

        for (int j = 0; j < n - 1; j++) {
            fprintf(izlez, "%s,", niza_line[indeksi[j]]);
        } fprintf(izlez, "%s\n", niza_line[indeksi[n - 1]]);
    }

    return 0;
}
