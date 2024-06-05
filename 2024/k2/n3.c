#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int maxLength = 0;
int maxPath[50]; // Store the longest path (x, y) pairs

// Possible moves for the jumper
int moves[8][2] = {
    {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
};

// Function to check if the move is valid
bool isValidMove(int n, bool** board, bool** visited, int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < n && !board[x][y] && !visited[x][y]);
}

// Recursive function to find the longest path
void findLongestPath(int n, bool** board, bool** visited, int x, int y, int* path, int length) {
    if (length > maxLength) {
        maxLength = length;
        for (int i = 0; i < 2 * length; i++) {
            maxPath[i] = path[i];
        }
    }

    for (int i = 0; i < 8; i++) {
        int newX = x + moves[i][0];
        int newY = y + moves[i][1];
        if (isValidMove(n, board, visited, newX, newY)) {
            visited[newX][newY] = true;
            path[2 * length] = newX;
            path[2 * length + 1] = newY;
            findLongestPath(n, board, visited, newX, newY, path, length + 1);
            visited[newX][newY] = false;
        }
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    // Initialize the board and visited arrays
    bool** board = (bool**)malloc(n * sizeof(bool*));
    bool** visited = (bool**)malloc(n * sizeof(bool*));
    for (int i = 0; i < n; i++) {
        board[i] = (bool*)calloc(n, sizeof(bool));
        visited[i] = (bool*)calloc(n, sizeof(bool));
    }

    // Read the positions of obstacles
    for (int i = 0; i < k; i++) {
        int v, s;
        scanf("%d %d", &v, &s);
        board[v][s] = true;
    }

    // Initialize the path array
    int path[50]; // Store the path as (x, y) pairs
    path[0] = 0;
    path[1] = 0;
    visited[0][0] = true;

    // Start finding the longest path
    findLongestPath(n, board, visited, 0, 0, path, 1);

    // Print the longest path
    for (int i = 1; i < maxLength; i++) {
        printf("%d/%d\n", maxPath[2 * i], maxPath[2 * i + 1]);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(board[i]);
        free(visited[i]);
    }
    free(board);
    free(visited);

    return 0;
}