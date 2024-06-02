#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 206. Reverse Linked List (LeetCode)

// Given the head of a singly linked list, reverse the list, and return the reversed list.


// Example 1:

// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Example 2:

// Input: head = [1,2]
// Output: [2,1]

// Example 3:

// Input: head = []
// Output: []


// Constraints:

// The number of nodes in the list is the range [0, 5000].
// -5000 <= Node.val <= 5000


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    ListNode* before = NULL;
    ListNode* next = NULL;

    while (head != NULL) {
        next = head->next;
        head->next = before;
        before = head;
        head = next;
    }

    return before;
}


///////////////////
//     Tests     //
///////////////////


// Helper function to create a linked list from an array
struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode) * size);
    struct ListNode* current = head;
    for (int i = 0; i < size; i++) {
        current->val = arr[i];
        if (i < size - 1) {
            current->next = &head[i + 1];
        } else {
            current->next = NULL;
        }
        current = current->next;
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

int main() {
    // Example 1
    int arr1[] = {1, 2, 3, 4, 5};
    struct ListNode* list1 = createList(arr1, 5);
    struct ListNode* result1 = reverseList(list1);
    printf("Example 1:\nInput: [1, 2, 3, 4, 5]\nOutput: ");
    printList(result1);

    // Example 2
    int arr2[] = {1, 2};
    struct ListNode* list2 = createList(arr2, 2);
    struct ListNode* result2 = reverseList(list2);
    printf("Example 2:\nInput: [1, 2]\nOutput: ");
    printList(result2);

    // Example 3
    int* arr3 = NULL;
    struct ListNode* list3 = createList(arr3, 0);
    struct ListNode* result3 = reverseList(list3);
    printf("Example 3:\nInput: []\nOutput: ");
    printList(result3);

    return 0;
}