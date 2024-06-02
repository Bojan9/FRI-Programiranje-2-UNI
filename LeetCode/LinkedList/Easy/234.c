#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 234. Palindrome Linked List (LeetCode)

// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.


// Example 1:

// Input: head = [1,2,2,1]
// Output: true

// Example 2:

// Input: head = [1,2]
// Output: false


// Constraints:

// The number of nodes in the list is in the range [1, 105].
// 0 <= Node.val <= 9


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

// Space O(n)
bool isPalindrome(struct ListNode* head) {
    int* table = malloc(100001 * sizeof(int));

    int n = 0;
    while (head != NULL) {
        table[n] = head->val;
        head = head->next;
        n++;
    }

    for (int i = 0; i < n/2; i++) {
        if (table[i] != table[n - i - 1]) {
            free(table);
            return false;
        }
    }

    free(table);
    return true;
}

// Space O(1)
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

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true;

    // Find the middle of the linked list
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    struct ListNode* secondHalf = reverseList(slow);
    struct ListNode* firstHalf = head;

    // Compare the first half and the reversed second half
    while (secondHalf != NULL) {
        if (firstHalf->val != secondHalf->val) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
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
    int arr1[] = {1, 2, 2, 1};
    struct ListNode* list1 = createList(arr1, 4);
    bool result1 = isPalindrome(list1);
    printf("Example 1:\nInput: [1, 2, 2, 1]\nOutput: %s\n", result1 ? "true" : "false");
    freeList(list1);

    // Example 2
    int arr2[] = {1, 2};
    struct ListNode* list2 = createList(arr2, 2);
    bool result2 = isPalindrome(list2);
    printf("Example 2:\nInput: [1, 2]\nOutput: %s\n", result2 ? "true" : "false");
    freeList(list2);

    // Custom Example 3
    int arr3[] = {1, 2, 3, 2, 1};
    struct ListNode* list3 = createList(arr3, 5);
    bool result3 = isPalindrome(list3);
    printf("Example 3:\nInput: [1, 2, 3, 2, 1]\nOutput: %s\n", result3 ? "true" : "false");
    freeList(list3);

    // Custom Example 4
    int arr4[] = {1};
    struct ListNode* list4 = createList(arr4, 1);
    bool result4 = isPalindrome(list4);
    printf("Example 4:\nInput: [1]\nOutput: %s\n", result4 ? "true" : "false");
    freeList(list4);

    // Custom Example 5
    int arr5[] = {1, 2, 3, 4, 5};
    struct ListNode* list5 = createList(arr5, 5);
    bool result5 = isPalindrome(list5);
    printf("Example 5:\nInput: [1, 2, 3, 4, 5]\nOutput: %s\n", result5 ? "true" : "false");
    freeList(list5);

    return 0;
}