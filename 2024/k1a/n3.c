#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int v, s;

    scanf("%d", &v);
    scanf("%d", &s);

    int** matrica = calloc(v, sizeof(int*));

    for (int i = 0; i < v; i++) {
        matrica[i] = calloc(s, sizeof(int));

        for (int j = 0; j < s; j++) {
            scanf("%d", &matrica[i][j]);
        }
    }

    int ne_nula = 0;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < s; j++) {
            if (matrica[i][j] != 0) {
                ne_nula++;
            }
        }
    }

    int* tabela1 = calloc(ne_nula, sizeof(int));
    int t1 = 0;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < s; j++) {
            if (matrica[i][j] != 0) {
                tabela1[t1] = matrica[i][j];
                t1++;
            }
        }
    }

    int* tabela2 = calloc(v + 1, sizeof(int));
    tabela2[0] = 0;
    int t2 = 1;
    int vk = 0;
    for (int i = 0; i < v; i++) {
        int cur_vk = 0;
        for (int j = 0; j < s; j++) {
            if (matrica[i][j] != 0) {
                cur_vk++;
            }
        }
        vk += cur_vk;
        tabela2[t2] = vk;
        t2++;
    }

    int* tabela3 = calloc(ne_nula, sizeof(int));
    int t3 = 0;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < s; j++) {
            if (matrica[i][j] != 0) {
                tabela3[t3] = j;
                t3++;
            }
        }
    }

    if (ne_nula != 0) {
        for (int i = 0; i < ne_nula - 1; i++) {
            printf("%d_", tabela1[i]);
        } printf("%d", tabela1[ne_nula - 1]);
    } printf("\n");

    for (int i = 0; i < v; i++) {
        printf("%d_", tabela2[i]);
    } printf("%d\n", tabela2[v]);

    if (ne_nula != 0) {
        for (int i = 0; i < ne_nula - 1; i++) {
            printf("%d_", tabela3[i]);
        } printf("%d\n", tabela3[ne_nula - 1]);
    }
    
    return 0;
}
