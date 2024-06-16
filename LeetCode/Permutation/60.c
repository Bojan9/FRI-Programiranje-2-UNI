#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 60. Permutation Sequence (LeetCode)

// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"

// Given n and k, return the kth permutation sequence.


// Example 1:

// Input: n = 3, k = 3
// Output: "213"

// Example 2:

// Input: n = 4, k = 9
// Output: "2314"

// Example 3:

// Input: n = 3, k = 1
// Output: "123"


// Constraints:

// 1 <= n <= 9
// 1 <= k <= n!


char* getPermutation(int n, int k) {
    // Resultant string for the kth permutation
    char *result = (char *)malloc((n + 1) * sizeof(char));
    result[n] = '\0'; // Null-terminate the string
    
    // Create an array of numbers to get indices from
    int *numbers = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        numbers[i] = i + 1;
    }
    
    // Create an array of factorial lookup
    int *factorial = (int *)malloc(n * sizeof(int));
    factorial[0] = 1;
    for (int i = 1; i < n; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
    
    // Decrement k by 1 to make it zero-indexed
    k--;
    
    for (int i = 0; i < n; i++) {
        int index = k / factorial[n - 1 - i];
        result[i] = '0' + numbers[index];
        
        // Remove the used number from the array
        for (int j = index; j < n - 1 - i; j++) {
            numbers[j] = numbers[j + 1];
        }
        
        // Update k
        k %= factorial[n - 1 - i];
    }
    
    // Free allocated memory
    free(numbers);
    free(factorial);
    
    return result;
}