#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 109. Convert Sorted List to Binary Search Tree (LeetCode)

// Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.


// Example 1:

// Input: head = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

// Example 2:

// Input: head = []
// Output: []


// Constraints:

// The number of nodes in head is in the range [0, 2 * 10^4].
// -10^5 <= Node.val <= 10^5


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

// Definition for a binary tree node.
typedef struct TreeNode TreeNode;

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

struct TreeNode* sortedListToBST(struct ListNode* head) {
    
}


///////////////////
//     Tests     //
///////////////////