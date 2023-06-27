#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void push(Stack *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++s->top] = c;
}

char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_correctly_parenthesized(char *expr) {
    Stack s;
    s.top = -1;
    int i, len = strlen(expr);

    for (i = 0; i < len; i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            push(&s, expr[i]);
        } else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}') {
            if (is_empty(&s)) {
                return 0;  // Unmatched closing bracket
            }
            char top = pop(&s);
            if ((top == '(' && expr[i] != ')') ||
                (top == '[' && expr[i] != ']') ||
                (top == '{' && expr[i] != '}')) {
                return 0;  // Mismatched opening and closing brackets
            }
        }
    }
    return is_empty(&s);  // If the stack is empty, the expression is correctly parenthesized
}
int main() {
    char expr[MAX_SIZE];
    printf("Enter an expression: ");
    fgets(expr, MAX_SIZE, stdin);

    if (is_correctly_parenthesized(expr)) {
        printf("The expression is correctly parenthesized\n");
    } else {
        printf("The expression is not correctly parenthesized\n");
    }
        printf("ruhani bhasin \n2022A1R075");
    return 0;
}
