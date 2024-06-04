#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 148. Sort List (LeetCode)

// Given the head of a linked list, return the list after sorting it in ascending order.


// Example 1:

// Input: head = [4,2,1,3]
// Output: [1,2,3,4]

// Example 2:

// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]

// Example 3:

// Input: head = []
// Output: []


// Constraints:

// The number of nodes in the list is in the range [0, 5 * 10^4].
// -10^5 <= Node.val <= 10^5


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

// Function to merge two sorted lists
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
     ListNode* dummy = malloc(sizeof(ListNode));
     ListNode* tail = dummy;

     while (l1 != NULL && l2 != NULL) {
          if (l1->val < l2->val) {
               tail->next = l1;
               l1 = l1->next;
          } else {
               tail->next = l2;
               l2 = l2->next;
          }
          tail = tail->next;
     }
     tail->next = (l1 != NULL) ? l1 : l2;
     return dummy->next;
}

// Function to find the middle of the list
struct ListNode* findMiddle(struct ListNode* head) {
     ListNode* slow = head;
     ListNode* fast = head->next;

     while (fast != NULL && fast->next != NULL) {
          slow = slow->next;
          fast = fast->next->next;
     }
     return slow;
}

struct ListNode* sortList(struct ListNode* head) {
     if (head == NULL || head->next == NULL) {
          return head;
     }

     ListNode* mid = findMiddle(head);
     ListNode* left = head;
     ListNode* right = mid->next;
     mid->next = NULL;

     left = sortList(left);
     right = sortList(right);

     return merge(left, right);
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

// Main function to test sortList
int main() {
     // Example 1
     int arr1[] = {4, 2, 1, 3};
     struct ListNode* list1 = createList(arr1, 4);
     struct ListNode* result1 = sortList(list1);
     printf("Example 1:\nInput: 4->2->1->3\nOutput: ");
     printList(result1);
     freeList(result1);

     // Example 2
     int arr2[] = {-1, 5, 3, 4, 0};
     struct ListNode* list2 = createList(arr2, 5);
     struct ListNode* result2 = sortList(list2);
     printf("Example 2:\nInput: -1->5->3->4->0\nOutput: ");
     printList(result2);
     freeList(result2);

     // Example 3
     int* arr3 = NULL;
     struct ListNode* list3 = createList(arr3, 0);
     struct ListNode* result3 = sortList(list3);
     printf("Example 3:\nInput: (empty list)\nOutput: ");
     printList(result3);
     freeList(result3);

     return 0;
}