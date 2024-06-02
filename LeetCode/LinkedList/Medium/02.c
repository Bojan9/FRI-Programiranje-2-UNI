#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 2. Add Two Numbers (LeetCode)

// You are given two non-empty linked lists representing two non-negative integers. 
// The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.


// Example 1:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]

// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]


// Constraints:

// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    ListNode* first = malloc(sizeof(ListNode));
    ListNode* now = first;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int n1 = (l1 != NULL) ? l1->val : 0;
        int n2 = (l2 != NULL) ? l2->val : 0;
        int sum = n1 + n2 + carry;

        carry = sum / 10;
        sum = sum % 10;

        now->val = sum;

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;

        if (l1 != NULL || l2 != NULL || carry != 0) {
            now->next = malloc(sizeof(ListNode));
            now = now->next;
        } else {
            now->next = NULL;
        }
    }

    return first;
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
    // Example 1
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    struct ListNode* l1 = createList(arr1, 3);
    struct ListNode* l2 = createList(arr2, 3);
    struct ListNode* result = addTwoNumbers(l1, l2);
    printf("Example 1:\nInput: l1 = [2, 4, 3], l2 = [5, 6, 4]\nOutput: ");
    printList(result);

    // Example 2
    int arr3[] = {0};
    int arr4[] = {0};
    l1 = createList(arr3, 1);
    l2 = createList(arr4, 1);
    result = addTwoNumbers(l1, l2);
    printf("Example 2:\nInput: l1 = [0], l2 = [0]\nOutput: ");
    printList(result);

    // Example 3
    int arr5[] = {9, 9, 9, 9, 9, 9, 9};
    int arr6[] = {9, 9, 9, 9};
    l1 = createList(arr5, 7);
    l2 = createList(arr6, 4);
    result = addTwoNumbers(l1, l2);
    printf("Example 3:\nInput: l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]\nOutput: ");
    printList(result);

    return 0;
}