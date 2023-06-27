#include <stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(int data) {
  if (top == MAX_SIZE - 1) {
    printf("Stack overflow!\n");
    return;
  }
  top++;
  stack[top] = data;
  printf("%d pushed to stack\n", data);
}

int pop() {
  if (top == -1) {
    printf("Stack underflow!\n");
    return -1;
  }
  int data = stack[top];
  top--;
  printf("%d popped from stack\n", data);
  return data;
}

int main() {
  int choice, data;
  do {
    printf("1. Push\n2. Pop\n3. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter data to push: ");
        scanf("%d", &data);
        push(data);
        break;
      case 2:
        pop();
        break;
      case 3:
        printf("Quitting...\n");
        break;
      default:
        printf("Invalid choice!\n");
        break;
    }
  } while (choice != 3);
  return 0;
}


