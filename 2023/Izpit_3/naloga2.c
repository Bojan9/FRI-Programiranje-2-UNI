#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int** zmehcaj(int** slika, int n, int m, int d) {
    // Create a new image represented in memory
    int new_n = n - 2 * d;
    int new_m = m - 2 * d;
    int** new_slika = (int**)malloc(new_n * sizeof(int*));
    
    // Iterate over the new image
    for (int i = 0; i < new_n; i++) {
        new_slika[i] = (int*)malloc(new_m * sizeof(int));
        for (int j = 0; j < new_m; j++) {
            // Calculate the average gray value
            int sum = 0;
            for (int di = -d; di <= d; di++) {
                for (int dj = -d; dj <= d; dj++) {
                    sum += slika[i + d + di][j + d + dj];
                }
            }
            new_slika[i][j] = sum / ((2 * d + 1) * (2 * d + 1));
        }
    }
    
    return new_slika;
}

int* SLIKA[] = {
    (int[]) {70, 50, 80, 10, 20, 60},
    (int[]) { 0, 40, 30, 10, 90, 20},
    (int[]) {80, 40,  0, 30, 70, 50},
};

int N = 3;
int M = 6;
int D = 1;

int main() {
    int** nova = zmehcaj(SLIKA, N, M, D);
    int noviN = N - 2 * D;
    int noviM = M - 2 * D;

    for (int i = 0; i < noviN; i++) {
        for (int j = 0; j < noviM; j++) {
            printf("%5d", nova[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < noviN; i++) {
        free(nova[i]);
    }
    free(nova);

    return 0;
}
