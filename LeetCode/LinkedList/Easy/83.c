#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 83. Remove Duplicates from Sorted List (LeetCode)

// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.


// Example 1:

// Input: head = [1,1,2]
// Output: [1,2]

// Example 2:

// Input: head = [1,1,2,3,3]
// Output: [1,2,3]


// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order.


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return head;

    ListNode* now = head;
    
    while (now->next != NULL) {
        if (now->val == now->next->val) {
            now->next = now->next->next;
        } else {
            now = now->next;
        }
    }

    return head;
}


///////////////////
//     Tests     //
///////////////////


// Helper function to create a linked list from an array
struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = head;
    for (int i = 0; i < size; i++) {
        current->val = arr[i];
        if (i < size - 1) {
            current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            current = current->next;
        } else {
            current->next = NULL;
        }
    }
    return head;
}

// Helper function to print a linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

// Helper function to free the memory allocated for a linked list
void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // Test case 1
    int arr1[] = {1, 1, 2};
    struct ListNode* list1 = createList(arr1, 3);
    struct ListNode* result1 = deleteDuplicates(list1);
    printf("Test case 1:\nInput: [1, 1, 2]\nOutput: ");
    printList(result1);
    freeList(result1);

    // Test case 2
    int arr2[] = {1, 1, 2, 3, 3};
    struct ListNode* list2 = createList(arr2, 5);
    struct ListNode* result2 = deleteDuplicates(list2);
    printf("Test case 2:\nInput: [1, 1, 2, 3, 3]\nOutput: ");
    printList(result2);
    freeList(result2);

    // Test case 3
    int* arr3 = NULL;
    struct ListNode* list3 = createList(arr3, 0);
    struct ListNode* result3 = deleteDuplicates(list3);
    printf("Test case 3:\nInput: []\nOutput: ");
    printList(result3);
    freeList(result3);

    return 0;
}