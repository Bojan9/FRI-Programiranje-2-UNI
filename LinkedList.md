# Mastering Linked Lists in C: Algorithms for Efficient Data Manipulation

## Table of contents

1. Linked lists
    - Definition
    - Singly-linked list
    - Doubly-linked list
2. Insertion
    - Insert a node at the beginning of the linked list
    - Insert a node at the end of the linked list 
    - Insert a node in a sorted linked list
3. Deletion
    - Delete a node at the beginning of the linked list
    - Delete a node at the end of the linked list
    - Delete a node with a specific 
    - Delete a node after a given node
4. Traversal
    - Size of a linked list
5. Reversal
    - Entire linked list
    - Reverse a linked list in groups of given size
    - Delete n-th node from the end
6. Slow and fast pointer
    - Middle of a linked list
    - Detect a loop and return where it begins
    - Detect and remove a loop
7. Intersection of two linked lists
8. Merge two sorted linked lists
9. Rotate linked list
10. Reorder a linked list in a specific pattern
11. Partition linked list
12. Other
    - Compare two strings represented as linked lists
    - Add two numbers represented by linked lists

---

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


```diff
+ Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode* next;
};


+ Definition for doubly-linked list.
struct ListNode {
    int val;
    struct ListNode* prev;
    struct ListNode* next;
};
```
---

## Insertion

### Insert a node at the beginning of the linked list

```diff
+ Create a new node, set next to the head of the linked list, return the new node.

ListNode* insert(ListNode* head, int value) {
    ListNode* new_head = malloc(sizeof(ListNode));
    new_head->val = value;
    new_head->next = head;
    
    return new_head;
}
```

### Insert a node at the end of the linked list 

```diff
+ Traverse to the end of the linked list.
+ Create a new node, set next of the previous node to the new node, return head.

ListNode* insert(ListNode* head, int value) {
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

### Insert a node in a sorted linked list

```diff
+ Create a new node, find the right place, return the original head or a new one.

ListNode* insert(ListNode* head, int value) {
    ListNode* prev = NULL;
    ListNode* temp = head;

    ListNode* new = malloc(sizeof(ListNode));
    new->val = value;
    
    while (temp != NULL) {
        if (temp->val > value) {
            new->next = temp;
            if (prev == NULL) {
                return new;
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

#### Space and time complexity

The time complexity of the insertion depends on the position where the new node is to be inserted in the sorted linked list. In the best case, when the new node is to be inserted at the beginning of the list, the time complexity is O(1). In the worst case, when the new node is to be inserted at the end of the list or the list is unsorted, the time complexity is O(n), where n is the number of nodes in the linked list.

The space complexity of the insertion is O(1), since it uses a constant amount of additional space to store the new node and the current node.

## Deletion

### Delete a node at the beginning of the linked list

```diff
+ Return the next node of the head node

ListNode* delete(ListNode* head) {
    return head->next;
}
```

### Delete a node at the end of the linked list

```diff
+ Go to the next to last node, set next to NULL, return head

ListNode* delete(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* temp = head;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;

    return head;
}
```

### Delete a node with a specific value

```diff
+ Find the node that has the same val as value, set the next of the prev node to the next of the current node, return old or new head

ListNode* delete(ListNode* head, int value) {
    ListNode* prev = NULL;
    ListNode* temp = head;

    while (temp->next != NULL) {
        if (temp->val == value) {
            if (prev == NULL) {
                return head->next;
            } else {
                prev->next = temp->next;
                return head;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    
    return head;
}
```

### Delete a node after a given node

```diff
+ Find the node that is the same as the k node, set the next of the current node to the next of the next node, return head

ListNode* delete(ListNode* head, ListNode* k) {
    ListNode* temp = head;

    while (temp->next != NULL) {
        if (temp == k) {
            temp->next = temp->next->next;
            return head;
        } else {
            temp = temp->next;
        }
    }
    
    return head;
}
```

#### Space and time complexity

The time complexity of this function is O(n) where n is the length of the linked list since we may have to traverse through the entire linked list to find the node to be deleted. The space complexity of this function is O(1) since we are only using constant amount of extra space, regardless of the size of the linked list.

## Traversal

### Size of a linked list
```diff
+ While the pointer doesn't point to a NULL, set the pointer to the next node and add 1 to the len variable.

int len(ListNode* head) {
    int len = 0;
    ListNode* temp = head;

    while (temp != NULL) {
        len++;
        temp = temp->next
    }

    return len;
}
```

#### Space and time complexity

The time complexity of this function is O(n) where n is the length of the linked list since we have to traverse through the entire linked list. The space complexity of this function is O(1) since we are only using constant amount of extra space, regardless of the size of the linked list.

## Reversal

### Entire linked list

```diff
+ Create 3 pointers, prev, temp and next. While temp is not NULL, change the values of the next pointer from next to prev. Return last node of the linked list (now first node)

ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* temp = head;
    ListNode* next = NULL;

    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    return prev;
}
```

#### Space and time complexity
The time complexity of this function is O(n) where n is the length of the linked list since we have to traverse through the entire linked list. The space complexity of this function is O(1) since we are only using constant amount of extra space, regardless of the size of the linked list.

### Reverse a linked list in groups of given size

```diff
! 1->2->3->4->5->6->7->8 and k = 3   --->   3->2->1->6->5->4->7->8
+ If len of linked list is less than k, leave it.
+ Else reverse the first k elements, call the function recursively by setting the next node of the original head and return the new head.

ListNode* reverse_k(ListNode* head, int k) {
    if (len(head) < k) {
        return head;
    }

    ListNode* prev = NULL;
    ListNode* temp = head;
    ListNode* next = NULL;

    for (int i = 0; i < k; i++) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    head->next = reverse_k(temp, k);

    return prev
}
```

#### Space and time complexity

The time complexity of this algorithm is O(n), where n is the total number of nodes in the linked list. This is because we traverse each node only once. The space complexity of this algorithm is O(1), since we only use a constant amount of extra space to store the three variables.

### Delete n-th node from the end

```diff
+ Reverse the linked list, find the n-th node, delete it, reverse it once again and return the head.

ListNode* delete(ListNode* head, int n) {
    ListNode* reverse_head = reverse(head);

    ListNode* prev = NULL;
    ListNode* temp = reverse_head;
    
    for (int i = 0; i < n - 1; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        reverse_head = reverse_head->next;
    } else {
        prev->next = temp->next;
    }

    return reverse(reverse_head);
}
```

#### Space and time complexity

The time complexity of this algorithm is O(n), where n is the total number of nodes in the linked list. The space complexity of this algorithm is O(1)

## Slow and fast pointer

### Middle of a linked list

```diff
+ Two pointers, one slow (goes to the next node) and one fast (jums 1 node). When the fast pointer reaches the end, the slow one will be in the middle of the linked list.
+ When there are even numbers in the linked list, if we want to get the first one, we will set fast to head->next, if we want to get the second, we will set fast to head.

ListNode* middle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
```

### Detect a loop and return where it begins

```diff
+ The function uses the Floyd’s cycle-finding algorithm to detect a loop in the given linked list. It uses two pointers, fast and slow, both initially set to the head of the linked list. fast moves twice as fast as slow by taking two steps at a time while slow moves one step at a time. If there is a loop in the linked list, fast and slow will eventually meet at some point inside the loop.
+ After detecting the loop, the function resets fast to the head of the linked list and moves both slow and fast one step at a time. When slow and fast meet, the node at which they meet is the start of the loop.

ListNode* loop(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;

    bool cycle = false;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) {
            cycle = true;
            break;
        }
    }

    if (cycle == false) {
        return NULL;
    } else {
        fast = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
}
```

### Detect and remove a loop

```diff
+ After we know the start of the loop, we make slow do another circle around the linked list and before it comes back at the start of the loop, we change the pointer of next to NULL.

ListNode* loop(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;

    bool cycle = false;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) {
            cycle = true;
            break;
        }
    }

    if (cycle == false) {
        return head;
    } else {
        fast = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        while (slow->next != fast) {
            slow = slow->next;
        }

        slow->next == NULL;

        return head;
    }
}
```

#### Space and time complexity

The time complexity of this function is O(n) where n is the number of nodes in the linked list. This is because the Floyd’s cycle-finding algorithm takes O(n) time to detect a loop, and the second traversal takes O(n) time as well.

The space complexity is O(1), since the function only uses a constant amount of extra space regardless of the input size.

## Intersection of two linked lists

```diff
! Solution 1 -> O(n + m) time | o(m) space
+ We concatenate list A and list B, which makes the new list have a loop at the point where list B connects with list A. Then we use Floyd’s cycle detection algorithm to detect the loop and find the start of the loop. The start of the loop is the intersection point of list A and list B.

ListNode* intersection(ListNode* head1, ListNode* head2) {
    ListNode* temp = head1;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head2;

    return loop(head1);
}
```

```diff
! Solution 2 -> O(nm) time | o(1) space
+ The second implementation has O(nm) time complexity and O(1) space complexity. In this implementation, we use two nested loops to iterate over each node in list A and list B. For each node in list A, we check if it is present in the set of nodes in list B.

ListNode* intersection(ListNode* head1, ListNode* head2) {
    while (head1 != NULL) {
        ListNode* temp = head2;

        while (temp != NULL) {
            if (head1 == temp) {
                return head1;
            }

            temp = temp->next;
        }

        head1 = head1->next;
    }

    return NULL;
}
```

## Merge two sorted linked lists 

```diff
+ We create a new linked list called merged, where we place elements in order from the other 2 linked lists.

ListNode* merge(ListNode* head1, ListNode* head2) {
    ListNode* merged = malloc(sizeof(ListNode));
    ListNode* temp = merged;

    while (head1 != NULL && head2 != NULL) {
        if (head1->val > head2->val) {
            temp->next = head2;
            head2 = head2->next;
        } else {
            temp->next = head1;
            head1 = head1->next;
        }
        temp = temp->next;
    }

    if (head1 == NULL) {
        temp->next = head2;
    } else {
        temp->next = head1;
    }

    return merged->next;
}
```

#### Space and time complexity

The time complexity for both implementations is O(n + m), where n is the number of nodes in the first linked list and m is the number of nodes in the second linked list. The space complexity for the iterative implementation is O(1) because we’re only using a few constant variables. The space complexity for the recursive implementation is O(n + m) because of the recursive calls.

## Rotate linked list

```diff
+ We find the length of the linked list, then find the new tail and new head and connect the old tail with the old head. At the end return the new head.

ListNode* rotate(ListNode* head, int k) {
    int n = len(head);
    k = k % n; // Adjust k if it is greater than the length of the list

    if (k == 0) {
        return head;
    }

    ListNode* prev = NULL;
    ListNode* temp = head;

    for (int i = 0; i < n - k; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (prev) {
        prev->next = NULL;
    }
    ListNode* new_head = temp;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = head;

    return new_head;
}
```

## Reorder a linked list in a specific pattern

```diff
+ First we find the middle of the linked list, then reverse the second half of the linked list and at the end merge the two halves.

ListNode* reorder(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Step 1: Find the middle of the linked list
    ListNode* middle = middle(head);

    // Step 2: Reverse the second half of the list
    ListNode* second_half = reverse(middle->next);
    middle->next = NULL;

    // Step 3: Merge the two halves
    ListNode* firstHalf = head;
    ListNode* temp1 = NULL;
    ListNode* temp2 = NULL;
    while (secondHalf != NULL) {
        temp1 = firstHalf->next;
        temp2 = secondHalf->next;

        firstHalf->next = secondHalf;
        secondHalf->next = temp1;

        firstHalf = temp1;
        secondHalf = temp2;
    }

    return head;
}
```

## Partition List

Let's consider a linked list: 1 -> 4 -> 3 -> 2 -> 5 -> 2 and a target value of 3. After partitioning, the list should be rearranged to: 1 -> 2 -> 2 -> 4 -> 3 -> 5.

```diff
+ We create 2 linked lists, and add elements to them whether they are smaller or greater than k, and at the end we combine them.

ListNode* partition(ListNode* head, int k) {
    ListNode* head_less = malloc(sizeof(ListNode));
    ListNode* head_more = malloc(sizeof(ListNode));

    ListNode* less = head_less;
    ListNode* more = head_more;

    while (head != NULL) {
        if (head->val < k) {
            less->next = head;
            less = less->next;
        } else {
            more->next = head;
            more = more->next;
        }
        head = head->next;
    }

    less->next = head_more->next;
    more->next = NULL;

    return head_less->next;
}
```

## Other

### Compare 2 strings as linked lists

To compare two strings, you need to compare the characters of the strings in order, from left to right. If the characters at the corresponding positions of both strings are the same, you move on to the next pair of characters. If the characters are different, the string with the lexicographically smaller character is considered to be smaller. If one string ends and the other does not, the shorter string is considered to be smaller. If both strings end at the same position and all characters match, then they are equal.

For example, if the first linked list is “abc” and the second linked list is “abd”, the function should return -1 because “abd” is lexicographically greater than “abc”.

```diff
+ While string1 and string2 are not NULL, compare the characters. If they are not the same or the len of the linked lists are not the same return 1 (or -1) else return 0;

int compare(ListNode* string1, ListNode* string2) {
    while (string1 != NULL && string2 != NULL) {
        if (string1->val > string2->val) {
            return 1;
        }

        if (string1-> val < string2->val) {
            return -1;
        }
    }

    if (string1 == NULL && string2 != NULL) {
        return -1;
    }

    if (string1 != NULL && string2 == NULL) {
        return 1;
    }

    return 0;
}
```

#### Space and time complexity

The time complexity of the code is O(n + m) where n and m are the number of nodes in list1 and list2, respectively. This is because the code traverses both lists once until either the end of a list is reached or characters don’t match.

The space complexity of the code is O(1) since the code only uses a constant amount of memory to store the current nodes being compared.

### Add 2 numbers as linked lists

```diff
+ The function takes two linked lists and returns a new linked list that is the sum of the input linked lists. First reverse the linked lists. Then, create a new linked list for a sum, and the nodes of the input linked lists are traversed simultaneously, adding the values of each node and the carry from the previous operation. The result is then stored as a new node in the output linked list. Finally, the output linked list is reversed again to obtain the correct order.

ListNode* add(ListNode* number1, ListNode* number2) {
    number1 = reverse(number1);
    number2 = reverse(number2);

    ListNode* result = malloc(sizeof(ListNode));
    ListNode* temp = result;
    int carry = 0;

    while (number1 != NULL || number2 != NULL || carry != 0) {
        int val1, val2;
        if (number1 != NULL) val1 = number1->val else val1 = 0;
        if (number2 != NULL) val2 = number2->val else val2 = 0;

        int sum = val1 + val2 + carry;
        carry = sum / 10;

        temp->val = sum % 10;

        ListNode* new = malloc(sizeof(ListNode));
        temp->next = new;
        temp = new;

        if (number1 != NULL) {
            number1 = number1->next;
        }
        if (number2 != NULL) {
            number2 = number2->next;
        }
    }


    return reverse(result);
}
```

#### Space and time complexity

The time complexity is O(n), where n is the length of the longer input linked list. This is because each node in the longer input linked list is traversed exactly once.