#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 109. Convert Sorted List to Binary Search Tree (LeetCode)

// (First solve 108.c)

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
     if (head == NULL) return NULL;
     if (head->next == NULL) {
          TreeNode* root = malloc(sizeof(TreeNode));
          root->val = head->val;
          root->left = NULL;
          root->right = NULL;

          return root;
     }

     ListNode* prev = head;
     ListNode* slow = head;
     ListNode* fast = head;

     while (fast && fast->next) {
          prev = slow;
          slow = slow->next;
          fast = fast->next->next;
     }

     prev->next = NULL;

     TreeNode* root = malloc(sizeof(TreeNode));
     root->val = slow->val;
     root->left = sortedListToBST(head);
     root->right = sortedListToBST(slow->next);

     return root;
}


///////////////////
//     Tests     //
///////////////////


// Helper function to create a new list node
ListNode* createListNode(int val) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Helper function to create a new tree node
TreeNode* createTreeNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Helper function to print the tree in level order traversal
void printLevelOrder(TreeNode* root) {
    if (!root) {
        printf("[]\n");
        return;
    }

    TreeNode* queue[10000];
    int start = 0, end = 0;

    queue[end++] = root;

    while (start < end) {
        TreeNode* node = queue[start++];
        if (node) {
            printf("%d ", node->val);
            queue[end++] = node->left;
            queue[end++] = node->right;
        } else {
            printf("null ");
        }
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

// Helper function to create a linked list from an array
ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    ListNode* head = createListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = createListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to free the linked list
void freeList(ListNode* head) {
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Example 1
    int arr1[] = {-10, -3, 0, 5, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    ListNode* list1 = createList(arr1, size1);
    TreeNode* tree1 = sortedListToBST(list1);
    printf("Example 1:\nInput: [-10, -3, 0, 5, 9]\nOutput: ");
    printLevelOrder(tree1);
    freeTree(tree1);
    freeList(list1);

    // Example 2
    ListNode* list2 = NULL;
    TreeNode* tree2 = sortedListToBST(list2);
    printf("Example 2:\nInput: []\nOutput: ");
    printLevelOrder(tree2);
    freeTree(tree2);
    freeList(list2);

    // Custom Example 3
    int arr3[] = {1, 2, 3, 4, 5};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    ListNode* list3 = createList(arr3, size3);
    TreeNode* tree3 = sortedListToBST(list3);
    printf("Custom Example 3:\nInput: [1, 2, 3, 4, 5]\nOutput: ");
    printLevelOrder(tree3);
    freeTree(tree3);
    freeList(list3);

    return 0;
}