#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 108. Convert Sorted Array to Binary Search Tree (LeetCode)

// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.


// Example 1:

// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

// Example 2:

// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.


// Constraints:

// 1 <= nums.length <= 10^4
// -10^4 <= nums[i] <= 10^4
// nums is sorted in a strictly increasing order.


// Definition for a binary tree node.
typedef struct TreeNode TreeNode;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* convertToBST(int* nums, int left, int right) {
    if (right < left) {
        return NULL;
    }

    int mid = (left + right) / 2;

    TreeNode* root = malloc(sizeof(TreeNode));
    root->val = nums[mid];
    root->left = convertToBST(nums, left, mid - 1);
    root->right = convertToBST(nums, mid + 1, right);

    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0) return NULL;
    return convertToBST(nums, 0, numsSize - 1);
}


///////////////////
//     Tests     //
///////////////////


// Helper function to print the tree in pre-order traversal
void printPreOrder(TreeNode* root) {
    if (root == NULL) {
        printf("null ");
        return;
    }
    printf("%d ", root->val);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Helper function to free the tree nodes
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // Example 1
    int nums1[] = {-10, -3, 0, 5, 9};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    TreeNode* tree1 = sortedArrayToBST(nums1, numsSize1);
    printf("Example 1:\nInput: [-10, -3, 0, 5, 9]\nOutput: ");
    printPreOrder(tree1);
    printf("\n");
    freeTree(tree1);

    // Example 2
    int nums2[] = {1, 3};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    TreeNode* tree2 = sortedArrayToBST(nums2, numsSize2);
    printf("Example 2:\nInput: [1, 3]\nOutput: ");
    printPreOrder(tree2);
    printf("\n");
    freeTree(tree2);

    // Custom Example 3
    int nums3[] = {0, 1, 2, 3, 4, 5};
    int numsSize3 = sizeof(nums3) / sizeof(nums3[0]);
    TreeNode* tree3 = sortedArrayToBST(nums3, numsSize3);
    printf("Custom Example 3:\nInput: [0, 1, 2, 3, 4, 5]\nOutput: ");
    printPreOrder(tree3);
    printf("\n");
    freeTree(tree3);

    return 0;
}