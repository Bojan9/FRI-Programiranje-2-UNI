#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function to perform pre-order traversal of the tree
void preOrderTraversal(int *tree, int index, int size) {
    if (index >= size) {
        return;
    }
    // Print the current node
    printf("%d", tree[index]);
    // Traverse the left subtree
    preOrderTraversal(tree, 2 * index + 1, size);
    // Traverse the right subtree
    preOrderTraversal(tree, 2 * index + 2, size);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int size = (1 << n) - 1; // Calculate the number of nodes in a complete binary tree of depth n
    
    int *tree = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        scanf("%d", &tree[i]);
    }
    
    // Perform pre-order traversal starting from the root (index 0)
    preOrderTraversal(tree, 0, size);
    printf("\n");
    
    free(tree);
    return 0;
}