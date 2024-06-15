#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// A utility function to find the index of an element in a 1D array
int findIndex(int* arr, int size, int element) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}

// A function to calculate the Manhattan distance between two cells in a grid
int manhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    int p, q, d;
    scanf("%d %d %d", &p, &q, &d);

    int size = p * q;
    int* cells = (int*)malloc(size * sizeof(int));

    // Read the cell numbers into the 1D array
    for (int i = 0; i < size; ++i) {
        scanf("%d", &cells[i]);
    }

    int fuel = d;
    int currentCellIndex = findIndex(cells, size, 0); // Start at cell 0
    int currentRow = currentCellIndex / q;
    int currentCol = currentCellIndex % q;

    int destinationCellIndex;
    for (int i = 1; i < size; ++i) {
        destinationCellIndex = findIndex(cells, size, i);
        int destinationRow = destinationCellIndex / q;
        int destinationCol = destinationCellIndex % q;

        int distance = manhattanDistance(currentRow, currentCol, destinationRow, destinationCol);

        if (fuel >= distance) {
            fuel -= distance;
            currentRow = destinationRow;
            currentCol = destinationCol;
        } else {
            printf("%d\n", i - 1);
            free(cells);
            return 0;
        }
    }

    // If Boris reaches the last cell
    printf("%d\n", size - 1);
    free(cells);
    return 0;
}