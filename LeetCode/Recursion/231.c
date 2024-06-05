#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 231. Power of Two (LeetCode)

// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2^x.


// Example 1:

// Input: n = 1
// Output: true
// Explanation: 2^0 = 1

// Example 2:

// Input: n = 16
// Output: true
// Explanation: 2^4 = 16

// Example 3:

// Input: n = 3
// Output: false


// Constraints:

// -2^31 <= n <= 2^31 - 1


bool isPowerOfTwo(int n) {
    if (n == 0) return false;
    return ((n == 1) || (n % 2 == 0 && isPowerOfTwo(n / 2)));
}

int main() {
    // Example 1
    int n1 = 1;
    printf("Example 1:\nInput: n = %d\nOutput: %s\n", n1, isPowerOfTwo(n1) ? "true" : "false");

    // Example 2
    int n2 = 16;
    printf("Example 2:\nInput: n = %d\nOutput: %s\n", n2, isPowerOfTwo(n2) ? "true" : "false");

    // Example 3
    int n3 = 3;
    printf("Example 3:\nInput: n = %d\nOutput: %s\n", n3, isPowerOfTwo(n3) ? "true" : "false");

    return 0;
}