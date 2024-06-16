#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_N 9
#define MAX_P 100
#define MAX_SEQ_LENGTH (2 * MAX_N * MAX_N)

int knight_moves[8][2] = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};

int is_valid_move(int x1, int y1, int x2, int y2) {
    for (int i = 0; i < 8; i++) {
        if (x1 + knight_moves[i][0] == x2 && y1 + knight_moves[i][1] == y2) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char *argv[]) {
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    int n, p;
    fscanf(input, "%d %d", &n, &p);

    char line[2 * MAX_SEQ_LENGTH * 3];
    char *moves[MAX_SEQ_LENGTH];
    char board[MAX_N][MAX_N];

    for (int i = 0; i < p; i++) {
        fscanf(input, " %[^\n]", line);

        int move_count = 0;
        char *token = strtok(line, " ");
        while (token != NULL) {
            moves[move_count++] = token;
            token = strtok(NULL, " ");
        }

        if (move_count != n * n) {
            fprintf(output, "0\n");
            continue;
        }

        memset(board, 0, sizeof(board));
        int valid = 1;

        for (int j = 0; j < move_count; j++) {
            int x = tolower(moves[j][0]) - 'a';
            int y = moves[j][1] - '1';

            if (x < 0 || x >= n || y < 0 || y >= n || board[x][y]) {
                valid = 0;
                break;
            }

            board[x][y] = 1;

            if (j > 0) {
                int prev_x = tolower(moves[j - 1][0]) - 'a';
                int prev_y = moves[j - 1][1] - '1';

                if (!is_valid_move(prev_x, prev_y, x, y)) {
                    valid = 0;
                    break;
                }
            }
        }

        fprintf(output, "%d\n", valid);
    }

    fclose(input);
    fclose(output);

    return 0;
}
