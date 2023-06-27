#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Binary Tree Node
struct Node {
    int data;
    bool is_empty;
};

// Binary Tree Array
struct Node tree[MAX_SIZE];

// Initialize the binary tree
void initTree() {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        tree[i].is_empty = true;
    }
}

// Get the index of the parent node
int getParentIndex(int index) {
    return (index - 1) / 2;
}

// Get the index of the left child node
int getLeftChildIndex(int index) {
    return (2 * index) + 1;
}

// Get the index of the right child node
int getRightChildIndex(int index) {
    return (2 * index) + 2;
}

// Insert a value into the binary tree
void insert(int value) {
    int i = 0;

    while (!tree[i].is_empty) {
        if (value <= tree[i].data) {
            i = getLeftChildIndex(i);
        } else {
            i = getRightChildIndex(i);
        }
    }

    tree[i].data = value;
    tree[i].is_empty = false;
}

// Search for a value in the binary tree
bool search(int value) {
    int i = 0;

    while (!tree[i].is_empty) {
        if (value == tree[i].data) {
            return true;
        } else if (value < tree[i].data) {
            i = getLeftChildIndex(i);
        } else {
            i = getRightChildIndex(i);
        }
    }

    return false;
}

// In-order traversal of the binary tree
void inorderTraversal(int index) {
    if (index < MAX_SIZE && !tree[index].is_empty) {
        inorderTraversal(getLeftChildIndex(index));
        printf("%d ", tree[index].data);
        inorderTraversal(getRightChildIndex(index));
    }
}

// Pre-order traversal of the binary tree
void preorderTraversal(int index) {
    if (index < MAX_SIZE && !tree[index].is_empty) {
        printf("%d ", tree[index].data);
        preorderTraversal(getLeftChildIndex(index));
        preorderTraversal(getRightChildIndex(index));
    }
}

// Post-order traversal of the binary tree
void postorderTraversal(int index) {
    if (index < MAX_SIZE && !tree[index].is_empty) {
        postorderTraversal(getLeftChildIndex(index));
        postorderTraversal(getRightChildIndex(index));
        printf("%d ", tree[index].data);
    }
}

// Delete a value from the binary tree
void delete(int value) {
    int i = 0;

    while (!tree[i].is_empty) {
        if (value == tree[i].data) {
            // Node to be deleted is found
            tree[i].is_empty = true;
            return;
        } else if (value < tree[i].data) {
            i = getLeftChildIndex(i);
        } else {
            i = getRightChildIndex(i);
        }
    }

    printf("Value not found in the binary tree.\n");
}

int main() {
    initTree();

    // Insert values into the binary tree
    insert(50);
    insert(30);
    insert(20);
    insert(40);
    insert(70);
    insert(60);
    insert(80);

    // Traversal examples
    printf("In-order traversal: ");
    inorderTraversal(0);
    printf("\n");

    printf("Pre-order traversal: ");
    preorderTraversal(0);
    printf("\n");

    printf("Post-order traversal: ");
    postorderTraversal(0);
    printf("\n");

    // Search for a value
    int searchValue = 60;
    if (search(searchValue)) {
        printf("Value %d found in the binary tree.\n", searchValue);
    } else {
        printf("Value %d not found in the binary tree.\n", searchValue);
    }

    // Delete a value
    int deleteValue = 30;
    delete(deleteValue);

    // In-order traversal after deletion
    printf("In-order traversal after deletion: ");
    inorderTraversal(0);
    printf("\n");

    return 0;
}
