#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the circular linked list
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to delete a node from the circular linked list
void deleteNode(struct Node** head, int key) {
    if (*head == NULL)
        return;

    struct Node *curr = *head, *prev;
    while (curr->data != key) {
        if (curr->next == *head) {
            printf("Node with key %d not found in the list.\n", key);
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    if (curr->next == *head) {
        *head = NULL;
        free(curr);
        return;
    }

    if (curr == *head)
        *head = (*head)->next;

    prev->next = curr->next;
    free(curr);
}

// Function to perform a linear search in the circular linked list
int search(struct Node* head, int key) {
    if (head == NULL)
        return 0;

    struct Node* current = head;
    do {
        if (current->data == key)
            return 1;
        current = current->next;
    } while (current != head);

    return 0;
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Driver code
int main() {
    struct Node* head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    printf("Initial circular linked list: ");
    display(head);

    deleteNode(&head, 30);
    printf("Circular linked list after deleting 30: ");
    display(head);

    int key = 20;
    if (search(head, key))
        printf("%d is present in the list.\n", key);
    else
        printf("%d is not present in the list.\n", key);

    key = 50;
    if (search(head, key))
        printf("%d is present in the list.\n", key);
    else
        printf("%d is not present in the list.\n", key);

    return 0;
}
