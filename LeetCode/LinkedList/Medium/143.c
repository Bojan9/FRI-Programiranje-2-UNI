#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 143. Reorder List (LeetCode)

// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln

// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

// You may not modify the values in the list's nodes. Only nodes themselves may be changed.


// Example 1:

// Input: head = [1,2,3,4]
// Output: [1,4,2,3]

// Example 2:

// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]


// Constraints:

// The number of nodes in the list is in the range [1, 5 * 104].
// 1 <= Node.val <= 1000


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

// Helper function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
     ListNode* prev = NULL;
     ListNode* current = head;
     ListNode* next = NULL;

     while (current != NULL) {
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
     }

     return prev;
}

// Helper function to merge two linked lists
struct ListNode* mergeLists(struct ListNode* l1, struct ListNode* l2) {
     ListNode* dummy = malloc(sizeof(ListNode));
     ListNode* tail = dummy;

     while (l1 != NULL && l2 != NULL) {
          tail->next = l1;
          l1 = l1->next;
          tail = tail->next;
          tail->next = l2;
          l2 = l2->next;
          tail = tail->next;
     }

     if (l1 != NULL) tail->next = l1;
     
     return dummy->next;
}

void reorderList(struct ListNode* head) {
     if (head == NULL || head->next == NULL) return;

     // Step 1: Find the middle of the list
     ListNode* slow = head;
     ListNode* fast = head;
     while (fast->next != NULL && fast->next->next != NULL) {
          slow = slow->next;
          fast = fast->next->next;
     }

     // Step 2: Split the list into two halves
     ListNode* secondHalf = slow->next;
     slow->next = NULL;

     // Step 3: Reverse the second half
     secondHalf = reverseList(secondHalf);

     // Step 4: Merge the two halves
     head = mergeLists(head, secondHalf);
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

// Helper function to free a linked list
void freeList(struct ListNode* head) {
     struct ListNode* current = head;
     while (current != NULL) {
          struct ListNode* next = current->next;
          free(current);
          current = next;
     }
}

// Main function to test reorderList
int main() {
     // Example 1
     int arr1[] = {1, 2, 3, 4};
     struct ListNode* list1 = createList(arr1, 4);
     printf("Example 1:\nInput: ");
     printList(list1);
     reorderList(list1);
     printf("Output: ");
     printList(list1);
     freeList(list1);

     // Example 2
     int arr2[] = {1, 2, 3, 4, 5};
     struct ListNode* list2 = createList(arr2, 5);
     printf("\nExample 2:\nInput: ");
     printList(list2);
     reorderList(list2);
     printf("Output: ");
     printList(list2);
     freeList(list2);

     return 0;
}