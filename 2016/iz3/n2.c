#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 10001 // Maximum length of input numbers

// Function to add two large numbers represented as strings
void addLargeNumbers(char *num1, char *num2, char *result) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    // Reverse the strings to start adding from the least significant digit
    strrev(num1);
    strrev(num2);

    int carry = 0;
    int maxLen = len1 > len2 ? len1 : len2;
    for (int i = 0; i < maxLen; ++i) {
        int digit1 = (i < len1) ? (num1[i] - '0') : 0;
        int digit2 = (i < len2) ? (num2[i] - '0') : 0;
        int sum = digit1 + digit2 + carry;
        result[i] = sum % 10 + '0';
        carry = sum / 10;
    }

    // If there's any remaining carry, add it to the result
    if (carry > 0) {
        result[maxLen] = carry + '0';
        result[maxLen + 1] = '\0';
    } else {
        result[maxLen] = '\0';
    }

    // Reverse the result to get the correct order
    strrev(result);
}

int main() {
    char num1[MAX_LEN], num2[MAX_LEN];
    scanf("%s", num1);
    scanf("%s", num2);

    char result[MAX_LEN + 1];
    addLargeNumbers(num1, num2, result);

    printf("%s\n", result);

    return 0;
}