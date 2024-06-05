#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 2487. Remove Nodes From Linked List (LeetCode)

// You are given the head of a linked list.

// Remove every node which has a node with a greater value anywhere to the right side of it.

// Return the head of the modified linked list.


// Example 1:

// Input: head = [5,2,13,3,8]
// Output: [13,8]
// Explanation: The nodes that should be removed are 5, 2 and 3.
// - Node 13 is to the right of node 5.
// - Node 13 is to the right of node 2.
// - Node 8 is to the right of node 3.

// Example 2:

// Input: head = [1,1,1,1]
// Output: [1,1,1,1]
// Explanation: Every node has value 1, so no nodes are removed.


// Constraints:

// The number of the nodes in the given list is in the range [1, 10^5].
// 1 <= Node.val <= 10^5


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

// Function to reverse the linked list
struct ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

struct ListNode* removeNodes(ListNode* head) {
    if (head == NULL) return NULL;

    head = reverseList(head);

    ListNode* curr = head;
    ListNode* maxNode = head;

    while (curr != NULL && curr->next != NULL) {
        if (curr->next->val < maxNode->val) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
            if (curr->val > maxNode->val) {
                maxNode = curr;
            }
        }
    }

    head = reverseList(head);

    return head;
}


///////////////////
//     Tests     //
///////////////////


// Helper function to create a new list node
ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Helper function to free the linked list
void freeList(ListNode* head) {
    ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Example 1
    ListNode* head1 = createNode(5);
    head1->next = createNode(2);
    head1->next->next = createNode(13);
    head1->next->next->next = createNode(3);
    head1->next->next->next->next = createNode(8);

    printf("Example 1:\nInput: [5, 2, 13, 3, 8]\nOutput: ");
    ListNode* result1 = removeNodes(head1);
    printList(result1);
    freeList(result1);

    // Example 2
    ListNode* head2 = createNode(1);
    head2->next = createNode(1);
    head2->next->next = createNode(1);
    head2->next->next->next = createNode(1);

    printf("Example 2:\nInput: [1, 1, 1, 1]\nOutput: ");
    ListNode* result2 = removeNodes(head2);
    printList(result2);
    freeList(result2);

    return 0;
}