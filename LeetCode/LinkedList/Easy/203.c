#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 203. Remove Linked List Elements (LeetCode)

// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.


// Example 1:

// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]

// Example 2:

// Input: head = [], val = 1
// Output: []

// Example 3:

// Input: head = [7,7,7,7], val = 7
// Output: []


// Constraints:

// The number of nodes in the list is in the range [0, 104].
// 1 <= Node.val <= 50
// 0 <= val <= 50


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

// Faster
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL) return NULL;

    ListNode* now = head;

    while (now->next != NULL) {
        if (now->next->val == val) {
            now->next = now->next->next;
        } else {
            now = now->next;
        }
    }

    if (head->val == val) {
        return head->next;
    }

    return head;
}

// Slower
struct ListNode* removeElements_slower(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) {
        head = head->next;
    }

    if (head == NULL) return NULL;

    ListNode* now = head->next;
    ListNode* before = head;

    while (now != NULL) {
        if (now->val == val) {
            before->next = now->next;
        } else {
            before = now;
        }
        now = now->next;
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
    int arr1[] = {1, 2, 6, 3, 4, 5, 6};
    struct ListNode* list1 = createList(arr1, 7);
    struct ListNode* result1 = removeElements(list1, 6);
    printf("Example 1:\nInput: [1, 2, 6, 3, 4, 5, 6], val = 6\nOutput: ");
    printList(result1);

    // Example 2
    int* arr2 = NULL;
    struct ListNode* list2 = createList(arr2, 0);
    struct ListNode* result2 = removeElements(list2, 1);
    printf("Example 2:\nInput: [], val = 1\nOutput: ");
    printList(result2);

    // Example 3
    int arr3[] = {7, 7, 7, 7};
    struct ListNode* list3 = createList(arr3, 4);
    struct ListNode* result3 = removeElements(list3, 7);
    printf("Example 3:\nInput: [7, 7, 7, 7], val = 7\nOutput: ");
    printList(result3);

    return 0;
}