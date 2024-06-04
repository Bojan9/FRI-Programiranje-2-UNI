#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 328. Odd Even Linked List (LeetCode)

// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Note that the relative order inside both the even and odd groups should remain as it was in the input.

// You must solve the problem in O(1) extra space complexity and O(n) time complexity.


// Example 1:

// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]

// Example 2:

// Input: head = [2,1,3,5,6,4,7]
// Output: [2,3,6,7,1,5,4]


// Constraints:

// The number of nodes in the linked list is in the range [0, 10^4].
// -10^6 <= Node.val <= 10^6


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL) return NULL;

    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* even_head = even;

    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    
    odd->next = even_head;

    return head;
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

int main() {
    // Example 1
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    ListNode* head1 = createLinkedList(arr1, size1);
    head1 = oddEvenList(head1);
    printf("Example 1:\nInput: head = [1, 2, 3, 4, 5]\nOutput: ");
    printLinkedList(head1);
    freeLinkedList(head1);

    // Example 2
    int arr2[] = {2, 1, 3, 5, 6, 4, 7};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    ListNode* head2 = createLinkedList(arr2, size2);
    head2 = oddEvenList(head2);
    printf("Example 2:\nInput: head = [2, 1, 3, 5, 6, 4, 7]\nOutput: ");
    printLinkedList(head2);
    freeLinkedList(head2);

    // Additional Test Case 1
    int arr3[] = {0};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    ListNode* head3 = createLinkedList(arr3, size3);
    head3 = oddEvenList(head3);
    printf("Additional Test Case 1:\nInput: head = [0]\nOutput: ");
    printLinkedList(head3);
    freeLinkedList(head3);

    // Additional Test Case 2
    int arr4[] = {1, 2};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    ListNode* head4 = createLinkedList(arr4, size4);
    head4 = oddEvenList(head4);
    printf("Additional Test Case 2:\nInput: head = [1, 2]\nOutput: ");
    printLinkedList(head4);
    freeLinkedList(head4);

    return 0;
}