#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 567. Permutation in String (LeetCode)

// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.


// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").

// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false


// Constraints:

// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.


bool checkInclusion(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    if (len1 > len2) {
        return false;
    }

    // Frequency arrays for characters in s1 and the current window in s2
    int count1[26] = {0};
    int count2[26] = {0};

    // Fill the frequency array for s1
    for (int i = 0; i < len1; i++) {
        count1[s1[i] - 'a']++;
    }

    // Initial window
    for (int i = 0; i < len1; i++) {
        count2[s2[i] - 'a']++;
    }

    // Compare the initial window
    bool isPermutation = true;
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            isPermutation = false;
            break;
        }
    }
    if (isPermutation) {
        return true;
    }

    // Slide the window over s2
    for (int i = len1; i < len2; i++) {
        // Add the new character to the current window
        count2[s2[i] - 'a']++;
        // Remove the character that is left behind
        count2[s2[i - len1] - 'a']--;

        // Compare the current window
        isPermutation = true;
        for (int j = 0; j < 26; j++) {
            if (count1[j] != count2[j]) {
                isPermutation = false;
                break;
            }
        }
        if (isPermutation) {
            return true;
        }
    }

    return false;
}


///////////////////
//     Tests     //
///////////////////


int main() {
    char s1[] = "ab";
    char s2[] = "eidbaooo";

    if (checkInclusion(s1, s2)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    char s3[] = "ab";
    char s4[] = "eidboaoo";

    if (checkInclusion(s3, s4)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}