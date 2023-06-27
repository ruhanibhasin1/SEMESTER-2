#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure for binary search tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node in the binary search tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

// In-order traversal of the binary search tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Search for a node in the binary search tree
struct Node* searchNode(struct Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return searchNode(root->left, data);
    else
        return searchNode(root->right, data);
}

// Find the minimum value node in a binary search tree
struct Node* findMinNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node from the binary search tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;

    // Insert nodes into the binary search tree
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Print the in-order traversal of the binary search tree
    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a node in the binary search tree
    int searchData = 40;
    struct Node* searchResult = searchNode(root, searchData);
    if (searchResult != NULL)
        printf("%d found in the binary search tree.\n", searchData);
    else
        printf("%d not found in the binary search tree.\n", searchData);

    // Delete a node from the binary search tree
    int deleteData = 30;
    root = deleteNode(root, deleteData);
    printf("In-order traversal after deleting %d: ", deleteData);
    inorderTraversal(root);
    printf("\n");

    return 0;
}
