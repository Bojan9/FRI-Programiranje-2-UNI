#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 86. Partition List (LeetCode)

// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.


// Example 1:

// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]

// Example 2:

// Input: head = [2,1], x = 2
// Output: [1,2]


// Constraints:

// The number of nodes in the list is in the range [0, 200].
// -100 <= Node.val <= 100
// -200 <= x <= 200


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x) {
     if (head == NULL) return NULL;

     ListNode* smaller_head = malloc(sizeof(ListNode));
     ListNode* smaller = smaller_head;

     ListNode* bigger_head = malloc(sizeof(ListNode));
     ListNode* bigger = bigger_head;

     while (head != NULL) {
          if (head->val < x) {
               smaller->next = head;
               smaller = smaller->next;
          } else {
               bigger->next = head;
               bigger = bigger->next;
          }
          head = head->next;
     }

     bigger->next = NULL;
     smaller->next = bigger_head->next;
     
     return smaller_head->next;
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
    int arr1[] = {1, 4, 3, 2, 5, 2};
    struct ListNode* list1 = createList(arr1, 6);
    struct ListNode* result1 = partition(list1, 3);
    printf("Example 1:\nInput: 1->4->3->2->5->2, x = 3\nOutput: ");
    printList(result1);
    freeList(result1);

    // Example 2
    int arr2[] = {2, 1};
    struct ListNode* list2 = createList(arr2, 2);
    struct ListNode* result2 = partition(list2, 2);
    printf("Example 2:\nInput: 2->1, x = 2\nOutput: ");
    printList(result2);
    freeList(result2);

    // Custom Example 3
    int arr3[] = {1};
    struct ListNode* list3 = createList(arr3, 1);
    struct ListNode* result3 = partition(list3, 5);
    printf("Custom Example 3:\nInput: 1, x = 2\nOutput: ");
    printList(result3);
    freeList(result3);

    return 0;
}