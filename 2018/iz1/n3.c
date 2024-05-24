#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int findMinDifference(int arr[], int n, int currentIndex, int currentSum, int totalSum) {
    if (currentIndex == n) {
        int diff = abs(totalSum - 2 * currentSum);
        return diff;
    }

    int includeDiff = findMinDifference(arr, n, currentIndex + 1, currentSum + arr[currentIndex], totalSum);
    int excludeDiff = findMinDifference(arr, n, currentIndex + 1, currentSum, totalSum);

    return (includeDiff < excludeDiff) ? includeDiff : excludeDiff;
}

int main() {
    int n;
    scanf("%d", &n);

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    int minDiff = findMinDifference(arr, n, 0, 0, totalSum);
    printf("%d\n", minDiff);

    free(arr);

    return 0;
}