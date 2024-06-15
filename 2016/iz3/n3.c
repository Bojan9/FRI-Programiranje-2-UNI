#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to count the number of valid paths for the frog
int countPaths(int n, int a, int b, int current, int visited, int **memo) {
    // If all stones have been visited exactly once
    if (visited == ((1 << n) - 1)) {
        return 1;
    }
    
    // Check if the result is already computed and stored in memo
    if (memo[current][visited] != -1) {
        return memo[current][visited];
    }

    int totalPaths = 0;
    for (int next = 0; next < n; ++next) {
        if (next != current && ((visited & (1 << next)) == 0)) {
            int diff = abs(current - next);
            if (diff >= a && diff <= b) {
                totalPaths += countPaths(n, a, b, next, (visited | (1 << next)), memo);
            }
        }
    }

    // Memoize the result
    memo[current][visited] = totalPaths;
    return totalPaths;
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    // Initialize memoization table
    int **memo = malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        memo[i] = malloc((1 << n) * sizeof(int));
        for (int j = 0; j < (1 << n); ++j) {
            memo[i][j] = -1;
        }
    }

    // Start the recursion from stone 0 (index 0)
    int result = countPaths(n, a, b, 0, 1, memo); // visited set with stone 0 visited

    // Free memoization table
    for (int i = 0; i < n; ++i) {
        free(memo[i]);
    }
    free(memo);

    // Output the result
    printf("%d\n", result);

    return 0;
}