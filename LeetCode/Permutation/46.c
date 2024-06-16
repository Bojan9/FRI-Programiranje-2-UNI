#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 46. Permutations (LeetCode)

// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.


// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Example 3:

// Input: nums = [1]
// Output: [[1]]


// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.


void backtrack(int* nums, int numsSize, int** result, int* returnSize, int* current, int* used, int depth) {
    if (depth == numsSize) {
        // Allocate memory for one permutation
        result[*returnSize] = (int*)malloc(numsSize * sizeof(int));
        // Copy the current permutation to the result
        for (int i = 0; i < numsSize; i++) {
            result[*returnSize][i] = current[i];
        }
        (*returnSize)++;
        return;
    }
    
    for (int i = 0; i < numsSize; i++) {
        if (!used[i]) {
            used[i] = 1;
            current[depth] = nums[i];
            backtrack(nums, numsSize, result, returnSize, current, used, depth + 1);
            used[i] = 0;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Calculate the number of permutations: numsSize!
    int numPermutations = 1;
    for (int i = 2; i <= numsSize; i++) {
        numPermutations *= i;
    }
    
    // Allocate memory for the result and column sizes
    int** result = (int**)malloc(numPermutations * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numPermutations * sizeof(int));
    *returnSize = 0;
    
    // Initialize the current permutation and used arrays
    int* current = (int*)malloc(numsSize * sizeof(int));
    int* used = (int*)calloc(numsSize, sizeof(int));
    
    // Call the backtrack function to generate all permutations
    backtrack(nums, numsSize, result, returnSize, current, used, 0);
    
    // Set the column sizes for each permutation
    for (int i = 0; i < numPermutations; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    
    // Free the temporary arrays
    free(current);
    free(used);
    
    return result;
}