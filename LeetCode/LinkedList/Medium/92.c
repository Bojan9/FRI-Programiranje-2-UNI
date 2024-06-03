#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 92. Reverse Linked List II (LeetCode)

// Given the head of a singly linked list and two integers left and right where left <= right,
// reverse the nodes of the list from position left to position right, and return the reversed list.


// Example 1:

// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]


// Constraints:

// The number of nodes in the list is n.
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
     if (left == right) return head;

     ListNode* dummy = malloc(sizeof(ListNode));
     dummy->next = head;
     ListNode* prev = dummy;

     for (int i = 1; i < left; i++) {
          prev = prev->next;
     }

     ListNode *curr = prev->next;
     ListNode *next = curr->next;

     for (int i = 0; i < right - left; i++) {
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
        next = curr->next;
    }

    return dummy->next;
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

// Testing the reverseBetween function
int main() {
    // Example 1
    int arr1[] = {1, 2, 3, 4, 5};
    struct ListNode* list1 = createList(arr1, 5);
    struct ListNode* result1 = reverseBetween(list1, 2, 4);
    printf("Example 1:\nInput: 1->2->3->4->5, left = 2, right = 4\nOutput: ");
    printList(result1);
    freeList(result1);

    // Example 2
    int arr2[] = {5};
    struct ListNode* list2 = createList(arr2, 1);
    struct ListNode* result2 = reverseBetween(list2, 1, 1);
    printf("Example 2:\nInput: 5, left = 1, right = 1\nOutput: ");
    printList(result2);
    freeList(result2);

    // Custom Example 3
    int arr3[] = {1, 2, 3, 4, 5};
    struct ListNode* list3 = createList(arr3, 5);
    struct ListNode* result3 = reverseBetween(list3, 1, 5);
    printf("Custom Example 3:\nInput: 1->2->3->4->5, left = 1, right = 5\nOutput: ");
    printList(result3);
    freeList(result3);

    return 0;
}