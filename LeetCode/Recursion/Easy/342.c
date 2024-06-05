#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 326. Power of Three (LeetCode)

// Given an integer n, return true if it is a power of four. Otherwise, return false.

// An integer n is a power of four, if there exists an integer x such that n == 4^x.


// Example 1:

// Input: n = 16
// Output: true

// Example 2:

// Input: n = 5
// Output: false

// Example 3:

// Input: n = 1
// Output: true


// Constraints:

// -2^31 <= n <= 2^31 - 1


bool isPowerOfFour(int n) {
    if (n == 0) return false;
    return ((n == 1) || (n % 4 == 0 && isPowerOfFour(n / 4)));
}


///////////////////
//     Tests     //
///////////////////


int main() {
    // Example 1
    int n1 = 16;
    printf("Example 1:\nInput: n = %d\nOutput: %s\n", n1, isPowerOfFour(n1) ? "true" : "false");

    // Example 2
    int n2 = 5;
    printf("Example 2:\nInput: n = %d\nOutput: %s\n", n2, isPowerOfFour(n2) ? "true" : "false");

    // Example 3
    int n3 = 1;
    printf("Example 3:\nInput: n = %d\nOutput: %s\n", n3, isPowerOfFour(n3) ? "true" : "false");

    return 0;
}