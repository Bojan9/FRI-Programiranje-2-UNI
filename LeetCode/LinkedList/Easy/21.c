#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 21. Merge Two Sorted Lists (LeetCode)

// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.


// Example 1:

// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:

// Input: list1 = [], list2 = []
// Output: []

// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]


// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    ListNode* first = malloc(sizeof(ListNode));
    ListNode* current = first;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }

    return first->next;
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

int main() {
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4, 5, 6, 7};
    struct ListNode* list1 = createList(arr1, 3);
    struct ListNode* list2 = createList(arr2, 6);

    struct ListNode* mergedList = mergeTwoLists(list1, list2);
    printf("Merged list:\n");
    printList(mergedList);

    return 0;
}