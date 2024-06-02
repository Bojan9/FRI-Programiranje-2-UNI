#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 24. Swap Nodes in Pairs (LeetCode)

// Given a linked list, swap every two adjacent nodes and return its head. 
// You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)


// Example 1:

// Input: head = [1,2,3,4]
// Output: [2,1,4,3]

// Example 2:

// Input: head = []
// Output: []

// Example 3:

// Input: head = [1]
// Output: [1]


// Constraints:

// The number of nodes in the list is in the range [0, 100].
// 0 <= Node.val <= 100


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;

    ListNode* newHead = head->next;
    ListNode* prev = NULL;

    while (head != NULL && head->next != NULL) {
        ListNode* nextPair = head->next->next;
        ListNode* second = head->next;

        second->next = head;
        head->next = nextPair;

        if (prev != NULL) {
            prev->next = second;
        }
        
        prev = head;
        head = nextPair;
    }

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
    int arr1[] = {1, 2, 3, 4};
    struct ListNode* list1 = createList(arr1, 4);
    struct ListNode* result1 = swapPairs(list1);
    printf("Example 1:\nInput: [1, 2, 3, 4]\nOutput: ");
    printList(result1);
    freeList(result1);

    // Example 2
    int* arr2 = NULL;
    struct ListNode* list2 = createList(arr2, 0);
    struct ListNode* result2 = swapPairs(list2);
    printf("Example 2:\nInput: []\nOutput: ");
    printList(result2);
    freeList(result2);

    // Example 3
    int arr3[] = {1};
    struct ListNode* list3 = createList(arr3, 1);
    struct ListNode* result3 = swapPairs(list3);
    printf("Example 3:\nInput: [1]\nOutput: ");
    printList(result3);
    freeList(result3);

    // Custom Example 4
    int arr4[] = {1, 2, 3, 4, 5};
    struct ListNode* list4 = createList(arr4, 5);
    struct ListNode* result4 = swapPairs(list4);
    printf("Custom Example 4:\nInput: [1, 2, 3, 4, 5]\nOutput: ");
    printList(result4);
    freeList(result4);

    // Custom Example 5
    int arr5[] = {1, 2, 3, 4, 5, 6};
    struct ListNode* list5 = createList(arr5, 6);
    struct ListNode* result5 = swapPairs(list5);
    printf("Custom Example 5:\nInput: [1, 2, 3, 4, 5, 6]\nOutput: ");
    printList(result5);
    freeList(result5);

    return 0;
}