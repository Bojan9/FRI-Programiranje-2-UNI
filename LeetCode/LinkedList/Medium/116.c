#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// 116. Populating Next Right Pointers in Each Node (LeetCode)

// You are given a perfect binary tree where all leaves are on the same level, and every parent has two children.

// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.


// Example 1:

// Input: root = [1,2,3,4,5,6,7]
// Output: [1,#,2,3,#,4,5,6,7,#]
// Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
// The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

// Example 2:

// Input: root = []
// Output: []


// Constraints:

// The number of nodes in the tree is in the range [0, 2^12 - 1].
// -1000 <= Node.val <= 1000


// Definition for a Node.
typedef struct Node Node;

struct Node {
     int val;
     struct Node *left;
     struct Node *right;
     struct Node *next;
};

struct Node* connect(struct Node* root) {
	
}


///////////////////
//     Tests     //
///////////////////