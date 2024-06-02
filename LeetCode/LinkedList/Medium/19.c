#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 19. Remove Nth Node From End of List (LeetCode)

// Given the head of a linked list, remove the nth node from the end of the list and return its head.


// Example 1:

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Example 2:

// Input: head = [1], n = 1
// Output: []

// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]


// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;

    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head->next == NULL) return NULL;

    struct ListNode* reverse_head = reverseList(head);

    struct ListNode* before = NULL;
    struct ListNode* now = reverse_head;

    for (int i = 0; i < n - 1; i++) {
        before = now;
        now = now->next;
    }

    if (before != NULL) {
        before->next = now->next;
    } else {
        reverse_head = now->next;
    }
    

    return reverseList(reverse_head);
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
    int n1 = 2;
    struct ListNode* result1 = removeNthFromEnd(list1, n1);
    printf("Example 1:\nInput: [1, 2, 3, 4, 5], n = 2\nOutput: ");
    printList(result1);
    freeList(result1);

    // Example 2
    int arr2[] = {1};
    struct ListNode* list2 = createList(arr2, 1);
    int n2 = 1;
    struct ListNode* result2 = removeNthFromEnd(list2, n2);
    printf("Example 2:\nInput: [1], n = 1\nOutput: ");
    printList(result2);
    freeList(result2);

    // Example 3
    int arr3[] = {1, 2};
    struct ListNode* list3 = createList(arr3, 2);
    int n3 = 1;
    struct ListNode* result3 = removeNthFromEnd(list3, n3);
    printf("Example 3:\nInput: [1, 2], n = 1\nOutput: ");
    printList(result3);
    freeList(result3);

    // Custom Example 4
    int arr4[] = {1, 2, 3};
    struct ListNode* list4 = createList(arr4, 3);
    int n4 = 3;
    struct ListNode* result4 = removeNthFromEnd(list4, n4);
    printf("Custom Example 4:\nInput: [1, 2, 3], n = 3\nOutput: ");
    printList(result4);
    freeList(result4);

    // Custom Example 5
    int arr5[] = {1, 2, 3, 4, 5, 6};
    struct ListNode* list5 = createList(arr5, 6);
    int n5 = 4;
    struct ListNode* result5 = removeNthFromEnd(list5, n5);
    printf("Custom Example 5:\nInput: [1, 2, 3, 4, 5, 6], n = 4\nOutput: ");
    printList(result5);
    freeList(result5);

    return 0;
}