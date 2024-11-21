#include<stdio.h>

#define STACK_SIZE 100

typedef struct {
    int data[STACK_SIZE];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == STACK_SIZE - 1;
}

void push(Stack* stack, int x) {
    if (isFull(stack)) {
        printf("Error: Stack is full.\n");
        return;
    }

    stack->top++;
    stack->data[stack->top] = x;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty.\n");
        return -1;
    }

    int x = stack->data[stack->top];
    stack->top--;
    return x;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty.\n");
        return -1;
    }
    return stack->data[stack->top];
}

int main(int argc, char const* argv[]) {
    /* Test */
    Stack s;
    initStack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d ", pop(&s));
    printf("%d ", peek(&s));
    printf("%d ", isEmpty(&s));

    return 0;
}