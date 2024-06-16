#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 37. Sudoku Solver (LeetCode)

// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

// The '.' character indicates empty cells.


// Example 1:

// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]


// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.


#define SIZE 9

bool isValid(char** board, int row, int col, char num) {
    for (int i = 0; i < SIZE; i++) {
        if (board[row][i] == num) return false;
        if (board[i][col] == num) return false;
        if (board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == num) return false;
    }
    return true;
}

bool solve(char** board, int row, int col) {
    if (row == SIZE) return true; // If we have reached the end of the board
    if (col == SIZE) return solve(board, row + 1, 0); // Move to the next row

    if (board[row][col] != '.') return solve(board, row, col + 1); // Skip filled cells

    for (char num = '1'; num <= '9'; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num; // Place the number
            if (solve(board, row, col + 1)) return true; // Continue with next cells
            board[row][col] = '.'; // Backtrack if placing num didn't solve the puzzle
        }
    }
    return false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve(board, 0, 0);
}


///////////////////
//     Tests     //
///////////////////


// Helper function to print the board
void printBoard(char** board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example Sudoku puzzle
    char* board[SIZE] = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };

    int boardColSize = SIZE;
    solveSudoku(board, SIZE, &boardColSize);

    printf("Solved Sudoku board:\n");
    printBoard(board);

    return 0;
}