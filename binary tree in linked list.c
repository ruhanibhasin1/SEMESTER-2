#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insertNode(root->left, data);
        } else {
            root->right = insertNode(root->right, data);
        }
        return root;
    }
}

// Function to search for a value in the binary tree
struct Node* searchNode(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return searchNode(root->left, data);
    }
    return searchNode(root->right, data);
}

// Function to perform inorder traversal of the binary tree (left -> root -> right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to delete a node from the binary tree
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Case 1: No child or only one child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Two children
        struct Node* minValueNode = root->right;
        while (minValueNode->left != NULL) {
            minValueNode = minValueNode->left;
        }
        root->data = minValueNode->data;
        root->right = deleteNode(root->right, minValueNode->data);
    }
    return root;
}

// Function to free the memory allocated to the binary tree
void freeBinaryTree(struct Node* root) {
    if (root != NULL) {
        freeBinaryTree(root->left);
        freeBinaryTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("Inorder traversal of the binary tree: ");
    inorderTraversal(root);
    printf("\n");

    struct Node* searchResult = searchNode(root, 40);
    if (searchResult != NULL) {
        printf("Node with value 40 found in the binary tree.\n");
    } else {
        printf("Node with value 40 not found in the binary tree.\n");
    }

    root = deleteNode(root, 40);
    printf("Inorder traversal after deleting 40: ");
    inorderTraversal(root);
    printf("\n");

    freeBinaryTree(root);
    root = NULL;

    return 0;
}
