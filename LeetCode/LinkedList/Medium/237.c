#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 237. Delete Node in a Linked List (LeetCode)

// There is a singly-linked list head and we want to delete a node node in it.

// You are given the node to be deleted node. You will not be given access to the first node of head.

// All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

// Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

// The value of the given node should not exist in the linked list.
// The number of nodes in the linked list should decrease by one.
// All the values before node should be in the same order.
// All the values after node should be in the same order.

// Custom testing:

// For the input, you should provide the entire linked list head and the node to be given node. node should not be the last node of the list and should be an actual node in the list.
// We will build the linked list and pass the node to your function.
// The output will be the entire list after calling your function.


// Example 1:

// Input: head = [4,5,1,9], node = 5
// Output: [4,1,9]
// Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.

// Example 2:

// Input: head = [4,5,1,9], node = 1
// Output: [4,5,9]
// Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.


// Constraints:

// The number of the nodes in the given list is in the range [2, 1000].
// -1000 <= Node.val <= 1000
// The value of each node in the list is unique.
// The node to be deleted is in the list and is not a tail node.


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
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

// Helper function to create a linked list from an array
ListNode* createLinkedList(int* arr, int size) {
    if (size == 0) return NULL;
    ListNode* head = createListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = createListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

// Helper function to free the linked list
void freeLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        ListNode* next = current->next;
        free(current);
        current = next;
    }
}

// Helper function to find a node by value (assuming all values are unique)
ListNode* findNode(ListNode* head, int value) {
    ListNode* current = head;
    while (current != NULL && current->val != value) {
        current = current->next;
    }
    return current;
}

int main() {
    // Example 1
    int arr1[] = {4, 5, 1, 9};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    ListNode* head1 = createLinkedList(arr1, size1);
    ListNode* node1 = findNode(head1, 5);
    deleteNode(node1);
    printf("Example 1:\nInput: head = [4, 5, 1, 9], node = 5\nOutput: ");
    printLinkedList(head1);
    freeLinkedList(head1);

    // Example 2
    int arr2[] = {4, 5, 1, 9};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    ListNode* head2 = createLinkedList(arr2, size2);
    ListNode* node2 = findNode(head2, 1);
    deleteNode(node2);
    printf("Example 2:\nInput: head = [4, 5, 1, 9], node = 1\nOutput: ");
    printLinkedList(head2);
    freeLinkedList(head2);

    // Additional test case
    int arr3[] = {1, 2, 3, 4, 5};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    ListNode* head3 = createLinkedList(arr3, size3);
    ListNode* node3 = findNode(head3, 3);
    deleteNode(node3);
    printf("Additional Test Case:\nInput: head = [1, 2, 3, 4, 5], node = 3\nOutput: ");
    printLinkedList(head3);
    freeLinkedList(head3);

    return 0;
}