#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

int main() {
    int n;
    scanf("%d", &n);

    int* sequence1 = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence1[i]);
    }

    int* sequence2 = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence2[i]);
    }

    int min_k = n-1;
    int t = 0;
    int i = 0;

    for (int j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            if (!(sequence2[i] == sequence1[(i + t) % 10])) {
                t++;
                break;
            }
        }
        if (i == n) {
            if (t < min_k) {
                min_k = t;
            }
        }    
    }
    
    printf("%d\n", min_k);

    free(sequence1);
    free(sequence2);

    return 0;
}
