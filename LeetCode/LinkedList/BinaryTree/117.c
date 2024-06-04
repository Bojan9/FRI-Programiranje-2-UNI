#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 117. Populating Next Right Pointers in Each Node II (LeetCode)

// Given a binary tree

// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.


// Example 1:

// Input: root = [1,2,3,4,5,null,7]
// Output: [1,#,2,3,#,4,5,7,#]
// Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
// The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

// Example 2:

// Input: root = []
// Output: []


// Constraints:

// The number of nodes in the tree is in the range [0, 6000].
// -100 <= Node.val <= 100


// Definition for a Node.
typedef struct Node Node;

struct Node {
     int val;
     struct Node *left;
     struct Node *right;
     struct Node *next;
};

struct Node* get_next_leftmost(Node* node) {
     Node* next = node->next;

	// If the next node have a left child return it,
	// if no left child, check the right child
	// otherwise, do the same for the next node until you find one or return NULL.
     
     while (next != NULL) {
          if (next->left != NULL) return next->left;
          if (next->right != NULL) return next->right;
          next = next->next;
     }

     return NULL;
}

struct Node* connect(struct Node* root) {
     if (root == NULL) return NULL;

     // get the next leftmost child for the current node if any.
     Node* next_leftmost = get_next_leftmost(root);

     // if there is a left and right childs, set the left next to the right child
	// if there is a left and no right child, set the left to the next_leftmost
     if (root->left) root->left->next = root->right ? root->right : next_leftmost;

     // if there is a right child, then set the right child next to the next_leftmost.
     if (root->right) root->right->next = next_leftmost;

	// Solve the right subtree first.
     connect(root->right);
		
	// Solve the left subtree next
     connect(root->left);
        
	// not useful in this implementation
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

     // Example 3
     Node* root3 = newNode(1);
     root3->left = newNode(2);

     Node* result3 = connect(root3);
     printf("Custom Test Case:\nInput: [1,2]\nOutput: ");
     printLevels(result3);
     freeTree(result3);

     return 0;
}