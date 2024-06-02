#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 82. Remove Duplicates from Sorted List II (LeetCode)

// Given the head of a sorted linked list, delete all nodes that have duplicate numbers,
// leaving only distinct numbers from the original list. Return the linked list sorted as well.


// Example 1:

// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]

// Example 2:

// Input: head = [1,1,1,2,3]
// Output: [2,3]


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

    ListNode* dummy = malloc(sizeof(ListNode));
    dummy->next = head;
    ListNode* before = dummy;
    
    while (head != NULL) {
        if (head->next != NULL && head->val == head->next->val) {
            while (head->next != NULL && head->val == head->next->val) {
                head = head->next;
            }
            before->next = head->next;
        } else {
            before = before->next;
        }

        head = head->next;
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

int main() {
    // Example 1
    int arr1[] = {1, 2, 3, 3, 4, 4, 5};
    struct ListNode* list1 = createList(arr1, 7);
    struct ListNode* result1 = deleteDuplicates(list1);
    printf("Example 1:\nInput: 1->2->3->3->4->4->5\nOutput: ");
    printList(result1);
    freeList(result1);

    // Example 2
    int arr2[] = {1, 1, 1, 2, 3};
    struct ListNode* list2 = createList(arr2, 5);
    struct ListNode* result2 = deleteDuplicates(list2);
    printf("Example 2:\nInput: 1->1->1->2->3\nOutput: ");
    printList(result2);
    freeList(result2);

    // Custom Example 3
    int arr3[] = {1, 1, 2, 3, 3, 4, 5, 5};
    struct ListNode* list3 = createList(arr3, 8);
    struct ListNode* result3 = deleteDuplicates(list3);
    printf("Custom Example 3:\nInput: 1->1->2->3->3->4->5->5\nOutput: ");
    printList(result3);
    freeList(result3);

    return 0;
}