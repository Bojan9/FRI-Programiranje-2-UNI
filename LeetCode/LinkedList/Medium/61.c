#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 61. Rotate List (LeetCode)

// Given the head of a linked list, rotate the list to the right by k places.


// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]

// Example 2:

// Input: head = [0,1,2], k = 4
// Output: [2,0,1]


// Constraints:

// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 10^9


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) return head;

    // Find the length of the list
    ListNode* current = head;
    int length = 1;

    while (current->next != NULL) {
        current = current->next;
        length++;
    }

    // Connect the last node to the head, forming a circular list
    current->next = head;
    
    // Find the new tail and new head
    k = k % length;
    int stepsToNewHead = length - k;
    ListNode* newTail = current;

    while (stepsToNewHead--) {
        newTail = newTail->next;
    }

    ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}


///////////////////
//     Tests     //
///////////////////


// Helper function to create a linked list from an array
struct ListNode* createList(int* arr, int size) {
    if (size == 0) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = arr[i];
        current->next = NULL;
    }
    return head;
}

// Helper function to free a linked list
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Helper function to print a linked list
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf("->");
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Example 1
    int arr1[] = {1, 2, 3, 4, 5};
    struct ListNode* list1 = createList(arr1, 5);
    struct ListNode* result1 = rotateRight(list1, 2);
    printf("Example 1:\nInput: [1, 2, 3, 4, 5], k = 2\nOutput: ");
    printList(result1);
    freeList(result1);

    // Example 2
    int arr2[] = {0, 1, 2};
    struct ListNode* list2 = createList(arr2, 3);
    struct ListNode* result2 = rotateRight(list2, 4);
    printf("Example 2:\nInput: [0, 1, 2], k = 4\nOutput: ");
    printList(result2);
    freeList(result2);

    // Custom Example 3
    int arr3[] = {1, 2, 3};
    struct ListNode* list3 = createList(arr3, 3);
    struct ListNode* result3 = rotateRight(list3, 3);
    printf("Custom Example 3:\nInput: [1, 2, 3], k = 3\nOutput: ");
    printList(result3);
    freeList(result3);

    return 0;
}