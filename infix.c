#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int data) {
  if (top == MAX_SIZE - 1) {
    printf("Stack overflow!\n");
    exit(1);
  }
  top++;
  stack[top] = data;
}

int pop() {
  if (top == -1) {
    printf("Stack underflow!\n");
    exit(1);
  }
  int data = stack[top];
  top--;
  return data;
}

int main() {
  char postfix[MAX_SIZE];
  printf("Enter a postfix expression: ");
  fgets(postfix, MAX_SIZE, stdin);
  int len = strlen(postfix);
  for (int i = 0; i < len; i++) {
    switch (postfix[i]) {
      case ' ':
        break;
      case '+':
      case '-':
      case '*':
      case '/':
      case '^': {
        int op2 = pop();
        int op1 = pop();
        int result;
        switch (postfix[i]) {
          case '+':
            result = op1 + op2;
            break;
          case '-':
            result = op1 - op2;
            break;
          case '*':
            result = op1 * op2;
            break;
          case '/':
            result = op1 / op2;
            break;
          case '^':
            result = pow(op1, op2);
            break;
        }
        push(result);
        break;
      }
      default: {
        int operand = 0;
        while (isdigit(postfix[i])) {
          operand = operand * 10 + (postfix[i] - '0');
          i++;
        }
        i--;
        push(operand);
        break;
      }
    }
  }
  printf("Result: %d\n", stack[top]);
  return 0;
}



