#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void findPaths(int cur, int n, int m, int k, int curk, int** povezavi, int* path, bool* visited, int tmp) {
    if (cur == n - 1) {
        printf("%d", path[0]);
        for (int j = 1; j < tmp; j++) {
            printf("->%d", path[j]);
        }
        printf("\n");
        return;
    }

    visited[cur] = true;

    for (int i = 0; i < m; i++) {
        if (povezavi[i][0] == cur && !visited[povezavi[i][1]] && povezavi[i][2] + curk <= k) {
            path[tmp] = povezavi[i][1];
            findPaths(povezavi[i][1], n, m, k, povezavi[i][2] + curk, povezavi, path, visited, tmp + 1);
        }
    }
    visited[cur] = false;
}

int main() {
    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);

    int** povezavi = (int**)malloc(m * sizeof(int*));

    for (int i = 0; i < m; i++) {
        povezavi[i] = (int*)malloc(3 * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &povezavi[i][0], &povezavi[i][1], &povezavi[i][2]);
    }

    int* path = (int*)malloc(n * sizeof(int));
    path[0] = 0;

    bool* visited = (bool*)calloc(n, sizeof(bool));

    findPaths(0, n, m, k, 0, povezavi, path, visited, 1);

    for (int i = 0; i < m; i++) {
        free(povezavi[i]);
    }
    free(povezavi);
    free(path);
    free(visited);

    return 0;
}