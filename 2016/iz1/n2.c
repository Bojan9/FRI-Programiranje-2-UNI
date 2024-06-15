#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_COORD 201 // Since coordinates range from -100 to 100, we need a 201x201 grid

int main() {
    int n;
    scanf("%d", &n);

    // Create a grid to track the number of times each cell is covered
    int** grid = calloc(MAX_COORD, sizeof(int*));
    for (int i = 0; i < MAX_COORD; ++i) {
        grid[i] = calloc(MAX_COORD, sizeof(int));
    }

    for (int i = 0; i < n; ++i) {
        int y, x, length;
        scanf("%d %d %d", &y, &x, &length);

        // Convert to positive indices for the grid
        int startY = y + 100;
        int startX = x + 100;

        // Mark the grid cells covered by the square
        for (int j = startY; j < startY + length; ++j) {
            for (int k = startX; k < startX + length; ++k) {
                grid[j][k]++;
            }
        }
    }

    // Allocate and initialize coverageCounts array
    int *coverageCounts = calloc(n + 1, sizeof(int));

    for (int i = 0; i < MAX_COORD; ++i) {
        for (int j = 0; j < MAX_COORD; ++j) {
            if (grid[i][j] > 0 && grid[i][j] <= n) {
                coverageCounts[grid[i][j]]++;
            }
        }
    }

    // Print the results
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", coverageCounts[i]);
    }

    // Free allocated memory
    for (int i = 0; i < MAX_COORD; ++i) {
        free(grid[i]);
    }
    free(grid);
    free(coverageCounts);

    return 0;
}