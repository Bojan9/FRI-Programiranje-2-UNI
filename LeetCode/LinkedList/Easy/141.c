#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 141. Linked List Cycle (LeetCode)

// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
// Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.


// Example 1:

// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

// Example 2:

// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

// Example 3:

// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.


// Constraints:

// The number of the nodes in the list is in the range [0, 104].
// -10^5 <= Node.val <= 10^5
// pos is -1 or a valid index in the linked-list.


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

// Floyd's Tortoise and Hare Algorithm
bool hasCycle(struct ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

// Or we can just create a for loop from 0 to 10.001 and check if head == NULL.
// If it is NULL return false, if we finish the loop return true.


///////////////////
//     Tests     //
///////////////////


// Helper function to create a linked list from an array
struct ListNode* createListWithCycle(int* arr, int size, int pos) {
    if (size == 0) return NULL;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode) * size);
    struct ListNode* current = head;
    struct ListNode* cycleNode = NULL;
    for (int i = 0; i < size; i++) {
        current->val = arr[i];
        if (i < size - 1) {
            current->next = &head[i + 1];
        } else {
            current->next = cycleNode;
        }
        if (i == pos) {
            cycleNode = current;
        }
        current = current->next;
    }
    return head;
}

int main() {
    // Example 1
    int arr1[] = {3, 2, 0, -4};
    int pos1 = 1;
    struct ListNode* list1 = createListWithCycle(arr1, 4, pos1);
    bool result1 = hasCycle(list1);
    printf("Example 1:\nInput: [3, 2, 0, -4] (Cycle at index %d)\nOutput: %s\n", pos1, result1 ? "true" : "false");

    // Example 2
    int arr2[] = {1, 2};
    int pos2 = 0;
    struct ListNode* list2 = createListWithCycle(arr2, 2, pos2);
    bool result2 = hasCycle(list2);
    printf("Example 2:\nInput: [1, 2] (Cycle at index %d)\nOutput: %s\n", pos2, result2 ? "true" : "false");

    // Example 3
    int arr3[] = {1};
    int pos3 = -1;
    struct ListNode* list3 = createListWithCycle(arr3, 1, pos3);
    bool result3 = hasCycle(list3);
    printf("Example 3:\nInput: [1] (No cycle)\nOutput: %s\n", result3 ? "true" : "false");

    return 0;
}