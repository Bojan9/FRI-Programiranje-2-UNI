#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 326. Power of Three (LeetCode)

// Given an integer n, return true if it is a power of three. Otherwise, return false.

// An integer n is a power of three, if there exists an integer x such that n == 3^x.


// Example 1:

// Input: n = 27
// Output: true
// Explanation: 27 = 3^3

// Example 2:

// Input: n = 0
// Output: false
// Explanation: There is no x where 3^x = 0.

// Example 3:

// Input: n = -1
// Output: false
// Explanation: There is no x where 3^x = (-1).


// Constraints:

// -2^31 <= n <= 2^31 - 1


bool isPowerOfThree(int n) {
    if (n == 0) return false;
    return ((n == 1) || (n % 3 == 0 && isPowerOfThree(n / 3)));
}


///////////////////
//     Tests     //
///////////////////


int main() {
    // Example 1
    int n1 = 27;
    printf("Example 1:\nInput: n = %d\nOutput: %s\n", n1, isPowerOfThree(n1) ? "true" : "false");

    // Example 2
    int n2 = 0;
    printf("Example 2:\nInput: n = %d\nOutput: %s\n", n2, isPowerOfThree(n2) ? "true" : "false");

    // Example 3
    int n3 = -1;
    printf("Example 3:\nInput: n = %d\nOutput: %s\n", n3, isPowerOfThree(n3) ? "true" : "false");

    return 0;
}