#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 142. Linked List Cycle II (LeetCode)

// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
// Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). 
// It is -1 if there is no cycle. Note that pos is not passed as a parameter.

// Do not modify the linked list.


// Example 1:

// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.

// Example 2:

// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the first node.

// Example 2:

// Input: head = [1], pos = -1
// Output: no cycle
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

struct ListNode *detectCycle(struct ListNode *head) {
     if (head == NULL || head->next == NULL) {
          return NULL;
     }
    
     ListNode *slow = head;
     ListNode *fast = head;
    
     // First part: Determine if there is a cycle
     while (fast && fast->next) {
          slow = slow->next;
          fast = fast->next->next;
          if (slow == fast) {
               break;
          }
     }

     // If there's no cycle
     if (fast == NULL || fast->next == NULL) {
          return NULL;
     }

     // Second part: Find the entry point of the cycle
     ListNode *finder = head;
     while (finder != slow) {
          finder = finder->next;
          slow = slow->next;
     }
     
     return finder;
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
            printf("->");
        }
        current = current->next;
    }
    printf("\n");
}

// Helper function to create a cycle in a linked list
void createCycle(struct ListNode* head, int pos) {
    if (pos == -1) return;
    struct ListNode* cycleNode = NULL;
    struct ListNode* current = head;
    int index = 0;
    while (current->next != NULL) {
        if (index == pos) {
            cycleNode = current;
        }
        current = current->next;
        index++;
    }
    current->next = cycleNode;
}

// Main function to test detectCycle
int main() {
    // Example 1: Cycle at position 1
    int arr1[] = {3, 2, 0, -4};
    struct ListNode* list1 = createList(arr1, 4);
    createCycle(list1, 1);
    struct ListNode* result1 = detectCycle(list1);
    printf("Example 1:\nInput: 3->2->0->-4 (cycle at position 1)\nOutput: ");
    if (result1) {
        printf("Cycle detected at node with value %d\n", result1->val);
    } else {
        printf("No cycle detected\n");
    }

    // Example 2: Cycle at position 0
    int arr2[] = {1, 2};
    struct ListNode* list2 = createList(arr2, 2);
    createCycle(list2, 0);
    struct ListNode* result2 = detectCycle(list2);
    printf("Example 2:\nInput: 1->2 (cycle at position 0)\nOutput: ");
    if (result2) {
        printf("Cycle detected at node with value %d\n", result2->val);
    } else {
        printf("No cycle detected\n");
    }

    // Example 3: No cycle
    int arr3[] = {1};
    struct ListNode* list3 = createList(arr3, 1);
    struct ListNode* result3 = detectCycle(list3);
    printf("Example 3:\nInput: 1\nOutput: ");
    if (result3) {
        printf("Cycle detected at node with value %d\n", result3->val);
    } else {
        printf("No cycle detected\n");
    }

    return 0;
}