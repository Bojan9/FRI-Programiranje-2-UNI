#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

enum {LEFT, UP, RIGHT, DOWN};

bool finished;

void rek(int m, int n, char*** lab, int* izpis, int idxx, int idxy, int came_from, int len) {
    if (idxx == m - 1 && idxy == n - 1) {
        for (int i = 0; i < len; i++) {
            printf("%d", izpis[i]);
        }
        finished = true;
    } else if (len < m * n && !finished) {
        for (int smer = LEFT; smer <= DOWN; smer++) {
            if (smer != came_from && lab[idxx][idxy][smer] == '0') {
                izpis[len] = smer;
                if (smer == LEFT) rek(m, n, lab, izpis, idxx, idxy - 1, RIGHT, len + 1);
				if (smer == UP) rek(m, n, lab, izpis, idxx - 1, idxy, DOWN, len + 1);
				if (smer == RIGHT) rek(m, n, lab, izpis, idxx, idxy + 1, LEFT, len + 1);
				if (smer == DOWN) rek(m, n, lab, izpis, idxx + 1, idxy, UP, len + 1);
            }
        }
    }
}

int main() {
    int m, n;

    scanf("%d %d", &m, &n);

    char*** lab = (char***)malloc(m * sizeof(char**));
    for (int i = 0; i < m; i++) {
        lab[i] = (char**)malloc(n * sizeof(char*));
        for (int j = 0; j < n; j++) {
            lab[i][j] = (char*)malloc(5 * sizeof(char));
            scanf("%s", lab[i][j]);
        }
    }

    int *izpis = (int *)malloc(m * n * sizeof(int));
    rek(m, n, lab, izpis, 0, 0, LEFT, 0);

    for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			free(lab[i][j]);
		}
		free(lab[i]);
	}
	free(lab);
	free(izpis);

    return 0;
}