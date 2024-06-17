# Linked List in C:

A linked list is a data structure that is commonly used in computer programming. It consists of a sequence of nodes, where each node contains a piece of data and a reference (or a “pointer”) to the next node in the sequence.

Linked lists are useful for representing sequences of data where the order of the data is important, but where the actual physical arrangement of the data in memory is not important. This is because linked lists can be easily modified to insert, delete or rearrange elements in constant time, regardless of the size of the list.

The main advantage of linked lists over other data structures such as arrays is that they can be used to build more complex data structures. For example, linked lists are used to implement stacks, queues, and hash tables.

Linked lists come in different variations, such as singly linked lists, doubly linked lists, and circular linked lists. In a singly linked list, each node has only one pointer to the next node in the list. In a doubly linked list, each node has two pointers, one to the next node and one to the previous node. In a circular linked list, the last node points back to the first node, forming a loop.

Examples: Here is an example schematic of a singly linked list structure:

```| 1 | -> | 2 | -> | 3 | -> | 4 | -> NULL```

Each node in the linked list has a value and a next pointer that points to the next node in the list. The last node in the list has a next pointer that points to NULL, indicating the end of the list.

Here is an example schematic of a doubly linked list structure:

```NULL <--> | 1 | <--> | 2 | <--> | 3 | <--> | 4 | <--> NULL```

Each node in the doubly linked list has a value, a prev pointer that points to the previous node in the list, and a next pointer that points to the next node in the list. The first node in the list has a prev pointer that points to NULL, indicating the beginning of the list, and the last node in the list has a next pointer that points to NULL, indicating the end of the list.


```
// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};


// Definition for doubly-linked list.
struct ListNode {
    int val;
    struct ListNode* prev;
    struct ListNode* next;
};
```

## Insertion

### Inser a node at the beginning of the linked list

```
ListNode* insert_beginning(ListNode* head, int value) {
    // Create a new node, set next to the head of the linked list, return the new node.

    ListNode* new_head = malloc(sizeof(ListNode));
    new_head->val = value;
    new_head->next = head;
    
    return new_head;
}
```

### Inser a node at the end of the linked list 

```
ListNode* insert_end(ListNode* head, int value) {
    // Traverse to the end of the linked list.
    // Create a new node, set next of the previous node to the new node, return head.

    ListNode* temp = head;
    
    while (temp->next != NULL) {
        temp = temp->next;
    }

    ListNode* new = malloc(sizeof(ListNode));
    new_head->val = value;
    new_head->next = NULL;

    temp->next = new;
    
    return head;
}
```

### Inser a node in a sorted linked list

```
ListNode* insert(ListNode* head, int value) {
    // Create a new node, find the right place, return the original head or a new one.

    ListNode* prev = NULL;
    ListNode* temp = head;

    ListNode* new = malloc(sizeof(ListNode));
    new->val = value;
    
    while (temp != NULL) {
        if (temp->val > value) {
            new->next = temp;
            // Check if temp is the head of the linked list, if yes return new as a new head
            if (prev == NULL) {
                return new;
            // else insert the new node and return the original head
            } else {
                prev->next = new;
                return head;
            }
        }

        prev = temp;
        temp = temp->next;
    }
    
    return head;
}
```