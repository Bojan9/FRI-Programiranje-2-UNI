#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// 1290. Convert Binary Number in a Linked List to Integer (LeetCode)

// Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. 
// The linked list holds the binary representation of a number.

// Return the decimal value of the number in the linked list.

// The most significant bit is at the head of the linked list.


// Example 1:

// Input: head = [1,0,1]
// Output: 5
// Explanation: (101) in base 2 = (5) in base 10

// Example 2:

// Input: head = [0]
// Output: 0


// Constraints:

// The Linked List is not empty.
// Number of nodes will not exceed 30.
// Each node's value is either 0 or 1.


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

// Faster
int getDecimalValue_slower(struct ListNode* head) {
    int binary = 0;
    while (head != NULL) {
        binary = binary * 2 + head->val;
        head = head->next;
    }

    return binary; 
}

// Slower
int getDecimalValue_slower(struct ListNode* head) {
    ListNode* dummy = head;
    
    int n = -1;
    while (dummy != NULL) {
        dummy = dummy->next;
        n++;
    }

    int binary = 0;
    while (head != NULL) {
        binary += (head->val * pow(2, n));
        head = head->next;
        n--;
    }

    return binary; 
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

int main() {
    // Example 1
    int arr1[] = {1, 0, 1};
    struct ListNode* list1 = createList(arr1, 3);
    int result1 = getDecimalValue(list1);
    printf("Example 1:\nInput: [1, 0, 1]\nOutput: %d\n", result1);
    freeList(list1);

    // Example 2
    int arr2[] = {0};
    struct ListNode* list2 = createList(arr2, 1);
    int result2 = getDecimalValue(list2);
    printf("Example 2:\nInput: [0]\nOutput: %d\n", result2);
    freeList(list2);

    // Custom Example 3
    int arr3[] = {1, 1, 1, 1};
    struct ListNode* list3 = createList(arr3, 4);
    int result3 = getDecimalValue(list3);
    printf("Example 3:\nInput: [1, 1, 1, 1]\nOutput: %d\n", result3);
    freeList(list3);

    // Custom Example 4
    int arr4[] = {1, 0, 0, 1};
    struct ListNode* list4 = createList(arr4, 4);
    int result4 = getDecimalValue(list4);
    printf("Example 4:\nInput: [1, 0, 0, 1]\nOutput: %d\n", result4);
    freeList(list4);

    // Custom Example 5
    int arr5[] = {1, 0, 1, 1, 0};
    struct ListNode* list5 = createList(arr5, 5);
    int result5 = getDecimalValue(list5);
    printf("Example 5:\nInput: [1, 0, 1, 1, 0]\nOutput: %d\n", result5);
    freeList(list5);

    return 0;
}