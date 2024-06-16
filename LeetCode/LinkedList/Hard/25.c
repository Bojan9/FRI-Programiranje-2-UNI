#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 25. Reverse Nodes in k-Group (LeetCode)

// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.


// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Example 2:

// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]


// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000


// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Helper function to reverse a linked list
struct ListNode* reverse(struct ListNode* head, int k) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;
    while (k-- > 0) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    // Check if we have at least k nodes to reverse
    struct ListNode* node = head;
    for (int i = 0; i < k; i++) {
        if (!node) return head; // Less than k nodes, return head as is
        node = node->next;
    }
    
    // Reverse first k nodes
    struct ListNode* newHead = reverse(head, k);
    // head is now the end of the reversed k nodes
    // Recursively call for the list starting from node and make the rest of the list as next of head
    head->next = reverseKGroup(node, k);
    
    return newHead;
}


///////////////////
//     Tests     //
///////////////////


// Helper function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}


// Helper function to print the linked list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

// Example usage
int main() {
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    int k = 2;
    printf("Original List: ");
    printList(head);

    head = reverseKGroup(head, k);

    printf("Reversed List in k groups: ");
    printList(head);

    return 0;
}