#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 876. Middle of the Linked List (LeetCode)

// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.


// Example 1:

// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.

// Example 2:

// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.


// Constraints:

// The number of nodes in the list is in the range [1, 100].
// 1 <= Node.val <= 100


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head) {
    ListNode* dummy = head;

    int n = 0;
    while (dummy != NULL) {
        dummy = dummy->next;
        n++;
    }
    free(dummy);

    n = n / 2;
    for (int i = 0; i < n; i++) {
        head = head->next;
    }

    return head;
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
    struct ListNode* result1 = middleNode(list1);
    printf("Example 1:\nInput: [1, 2, 3, 4, 5]\nOutput: ");
    printList(result1);

    // Example 2
    int arr2[] = {1, 2, 3, 4, 5, 6};
    struct ListNode* list2 = createList(arr2, 6);
    struct ListNode* result2 = middleNode(list2);
    printf("Example 2:\nInput: [1, 2, 3, 4, 5, 6]\nOutput: ");
    printList(result2);

    return 0;
}