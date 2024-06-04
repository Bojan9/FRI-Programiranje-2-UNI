#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 114. Flatten Binary Tree to Linked List (LeetCode)

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.

// The "linked list" should be in the same order as a pre-order traversal of the binary tree.


// Example 1:

// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]

// Example 2:

// Input: root = []
// Output: []

// Example 3:

// Input: root = [0]
// Output: [0]


// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -100 <= Node.val <= 100


// Definition for a binary tree node.
typedef struct TreeNode TreeNode;

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

struct TreeNode* rightmost(TreeNode* root) {
     if (root->right == NULL) return root;
     return rightmost(root->right);
}

void flatten(TreeNode* root) {
     if (root == NULL) return;

     TreeNode* nextRight = malloc(sizeof(TreeNode));
     TreeNode* rightMost = malloc(sizeof(TreeNode));

     while (root) {
          if (root->left) {
               rightMost = rightmost(root->left);
               nextRight = root->right;
               root->right = root->left;
               root->left = NULL;
               rightMost->right = nextRight;
          }
          root = root->right;
     }
}


///////////////////
//     Tests     //
///////////////////


// Helper function to create a new tree node
TreeNode* createTreeNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function to print the tree as a flattened list
void printFlattenedList(TreeNode* root) {
    while (root != NULL) {
        printf("%d ", root->val);
        root = root->right;
    }
    printf("\n");
}

// Helper function to free the tree nodes
void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Helper function to create a binary tree from an array
TreeNode* createTreeFromArray(int* arr, int size) {
    if (size == 0) return NULL;
    TreeNode** nodes = (TreeNode**)malloc(size * sizeof(TreeNode*));
    for (int i = 0; i < size; i++) {
        if (arr[i] != -1) {
            nodes[i] = createTreeNode(arr[i]);
        } else {
            nodes[i] = NULL;
        }
    }
    for (int i = 0, j = 1; j < size; i++) {
        if (nodes[i] != NULL) {
            if (j < size) nodes[i]->left = nodes[j++];
            if (j < size) nodes[i]->right = nodes[j++];
        }
    }
    TreeNode* root = nodes[0];
    free(nodes);
    return root;
}

int main() {
    // Example 1
    int arr1[] = {1, 2, 5, 3, 4, -1, 6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    TreeNode* tree1 = createTreeFromArray(arr1, size1);
    flatten(tree1);
    printf("Example 1:\nInput: [1, 2, 5, 3, 4, null, 6]\nOutput: ");
    printFlattenedList(tree1);
    freeTree(tree1);

    // Example 3
    int arr3[] = {0};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    TreeNode* tree3 = createTreeFromArray(arr3, size3);
    flatten(tree3);
    printf("Example 3:\nInput: [0]\nOutput: ");
    printFlattenedList(tree3);
    freeTree(tree3);

    return 0;
}