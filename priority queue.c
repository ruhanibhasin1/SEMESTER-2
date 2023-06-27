#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the priority queue
struct Node {
    int data;            // Data stored in the node
    int priority;        // Priority of the node
    struct Node* next;   // Pointer to the next node
};

// Structure to represent the priority queue
struct PriorityQueue {
    struct Node* front;  // Pointer to the front of the queue
};

// Function to create a new node
struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty priority queue
struct PriorityQueue* createPriorityQueue() {
    struct PriorityQueue* newQueue = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    if (newQueue == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newQueue->front = NULL;
    return newQueue;
}

// Function to check if the priority queue is empty
int isEmpty(struct PriorityQueue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue an element into the priority queue
void enqueue(struct PriorityQueue* queue, int data, int priority) {
    struct Node* newNode = createNode(data, priority);

    // If the queue is empty or the new node has higher priority than the front node
    if (isEmpty(queue) || priority < queue->front->priority) {
        newNode->next = queue->front;
        queue->front = newNode;
    } else {
        struct Node* temp = queue->front;

        // Find the position to insert the new node
        while (temp->next != NULL && priority >= temp->next->priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to dequeue the element with the highest priority from the queue
int dequeue(struct PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Priority queue is empty!\n");
        exit(1);
    }

    struct Node* frontNode = queue->front;
    int data = frontNode->data;

    queue->front = frontNode->next;
    free(frontNode);

    return data;
}

// Function to display the elements of the priority queue
void display(struct PriorityQueue* queue) {
    if (isEmpty(queue)) {
        printf("Priority queue is empty!\n");
        return;
    }

    struct Node* temp = queue->front;
    printf("Priority Queue: ");
    while (temp != NULL) {
        printf("[%d:%d] ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("\n");
}

// Function to test the priority queue implementation
int main() {
    struct PriorityQueue* queue = createPriorityQueue();

    enqueue(queue, 10, 2);
    enqueue(queue, 20, 1);
    enqueue(queue, 30, 3);
    enqueue(queue, 40, 2);
    enqueue(queue, 50, 1);

    display(queue);

    int element = dequeue(queue);
    printf("Dequeued element: %d\n", element);

    element = dequeue(queue);
    printf("Dequeued element: %d\n", element);

    display(queue);

    return 0;
}
