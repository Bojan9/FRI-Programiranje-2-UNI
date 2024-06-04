#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 116. Populating Next Right Pointers in Each Node (LeetCode)

// You are given a perfect binary tree where all leaves are on the same level, and every parent has two children.

// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.


// Example 1:

// Input: root = [1,2,3,4,5,6,7]
// Output: [1,#,2,3,#,4,5,6,7,#]
// Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
// The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

// Example 2:

// Input: root = []
// Output: []


// Constraints:

// The number of nodes in the tree is in the range [0, 2^12 - 1].
// -1000 <= Node.val <= 1000


// Definition for a Node.
typedef struct Node Node;

struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

struct Node* connect(struct Node* root) {
	if (root == NULL) return root;
    if (root->left == NULL || root->right == NULL) return root;

    root->left->next = root->right;
    if (root->next) {
        root->right->next = root->next->left;
    } else {
        root->right->next = NULL;
    }

    connect(root->left);
    connect(root->right);

    return root;
}


///////////////////
//     Tests     //
///////////////////


// Function to create a new node
Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = node->next = NULL;
    return node;
}

// Function to print the tree level-by-level
void printLevels(Node* root) {
    if (!root) return;

    Node* start = root;
    while (start) {
        Node* current = start;
        while (current) {
            printf("%d", current->val);
            if (current->next) {
                printf("->");
            }
            current = current->next;
        }
        printf("->#\n");
        start = start->left;
    }
}

// Function to free the tree
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main function for testing
int main() {
    // Example 1
    Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root1->right->left = newNode(6);
    root1->right->right = newNode(7);

    Node* result1 = connect(root1);
    printf("Example 1:\nInput: [1,2,3,4,5,6,7]\nOutput: ");
    printLevels(result1);
    freeTree(result1);

    // Example 2
    Node* root2 = NULL;
    Node* result2 = connect(root2);
    printf("Example 2:\nInput: []\nOutput: []\n");
    printLevels(result2);
    freeTree(result2);

    return 0;
}