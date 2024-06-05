#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 394. Different Ways to Add Parentheses (LeetCode)

// Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. 
// You may return the answer in any order.

// The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 10^4.


// Example 1:

// Input: expression = "2-1-1"
// Output: [0,2]
// Explanation:
// ((2-1)-1) = 0 
// (2-(1-1)) = 2

// Example 2:

// Input: expression = "2*3-4*5"
// Output: [-34,-14,-10,-10,10]
// Explanation:
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10


// Constraints:

// 1 <= expression.length <= 20
// expression consists of digits and the operator '+', '-', and '*'.
// All the integer values in the input expression are in the range [0, 99].


// Helper function to perform arithmetic operations
int calculate(int a, char operator, int b) {
    switch (operator) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        default: return 0;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// Main function to compute all possible results
int* diffWaysToCompute(char* expression, int* returnSize) {
    int n = strlen(expression);
    int* results = malloc(10000 * sizeof(int));
    *returnSize = 0;
    
    int isNumber = 1;
    for (int i = 0; i < n; i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            isNumber = 0;
            
            int leftSize = 0;
            int* leftResults = diffWaysToCompute(strndup(expression, i), &leftSize);
            int rightSize = 0;
            int* rightResults = diffWaysToCompute(strdup(expression + i + 1), &rightSize);
            
            for (int j = 0; j < leftSize; j++) {
                for (int k = 0; k < rightSize; k++) {
                    results[(*returnSize)++] = calculate(leftResults[j], expression[i], rightResults[k]);
                }
            }
            
            free(leftResults);
            free(rightResults);
        }
    }
    
    if (isNumber) {
        results[(*returnSize)++] = atoi(expression);
    }
    
    return results;
}


///////////////////
//     Tests     //
///////////////////


// Helper function to print the result array
void printResults(int* results, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        if (i > 0) printf(", ");
        printf("%d", results[i]);
    }
    printf("]\n");
}

// Test function
void testDiffWaysToCompute() {
    char expression1[] = "2-1-1";
    int size1;
    int* result1 = diffWaysToCompute(expression1, &size1);
    printf("Input: %s\nOutput: ", expression1);
    printResults(result1, size1);
    free(result1);
    
    char expression2[] = "2*3-4*5";
    int size2;
    int* result2 = diffWaysToCompute(expression2, &size2);
    printf("Input: %s\nOutput: ", expression2);
    printResults(result2, size2);
    free(result2);
}

int main() {
    testDiffWaysToCompute();
    return 0;
}