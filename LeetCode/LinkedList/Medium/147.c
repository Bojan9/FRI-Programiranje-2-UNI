#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 147. Insertion Sort List (LeetCode)

// Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

// The steps of the insertion sort algorithm:

// Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
// At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
// It repeats until no input elements remain.

// The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. 
// One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.


// Example 1:

// Input: head = [4,2,1,3]
// Output: [1,2,3,4]

// Example 2:

// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]


// Constraints:

// The number of nodes in the list is in the range [1, 5000].
// -5000 <= Node.val <= 5000


// Definition for singly-linked list.
typedef struct ListNode ListNode;

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head) {
     if (!head) return NULL;

     ListNode* dummy = malloc(sizeof(ListNode));
     dummy->next = NULL;
     ListNode* curr = head;

     while (curr != NULL) {
          ListNode* prev = dummy;
          ListNode* next = dummy->next;

          while (next != NULL && next->val < curr->val) {
               prev = next;
               next = next->next;
          }

          ListNode* temp = curr->next;
          curr->next = next;
          prev->next = curr;
          curr = temp;
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

// Main function to test insertionSortList
int main() {
     // Example 1
     int arr1[] = {4, 2, 1, 3};
     struct ListNode* list1 = createList(arr1, 4);
     struct ListNode* result1 = insertionSortList(list1);
     printf("Example 1:\nInput: 4->2->1->3\nOutput: ");
     printList(result1);
     freeList(result1);

     // Example 2
     int arr2[] = {-1, 5, 3, 4, 0};
     struct ListNode* list2 = createList(arr2, 5);
     struct ListNode* result2 = insertionSortList(list2);
     printf("Example 2:\nInput: -1->5->3->4->0\nOutput: ");
     printList(result2);
     freeList(result2);

     return 0;
}