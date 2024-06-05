#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 326. Power of Three (LeetCode)

// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.

// Given n, calculate F(n).


// Example 1:

// Input: n = 2
// Output: 1
// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

// Example 2:

// Input: n = 3
// Output: 2
// Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

// Example 3:

// Input: n = 4
// Output: 3
// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.


// Constraints:

// 0 <= n <= 30


int fib(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;

    return fib(n - 1) + fib(n - 2);
}


///////////////////
//     Tests     //
///////////////////


int main() {
    // Example 1
    int n1 = 2;
    printf("Example 1:\nInput: n = %d\nOutput: %d\n", n1, fib(n1));

    // Example 2
    int n2 = 3;
    printf("Example 2:\nInput: n = %d\nOutput: %d\n", n2, fib(n2));

    // Example 3
    int n3 = 4;
    printf("Example 3:\nInput: n = %d\nOutput: %d\n", n3, fib(n3));

    return 0;
}