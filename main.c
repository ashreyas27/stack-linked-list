#include <stdlib.h>
#include <stdio.h>

typedef struct Stack Stack;
typedef struct Node Node;

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;
};

void push(Stack* stack, int data) {
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Stack overflow while push()");
        return;
    }
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if(stack->top == NULL) {
        printf("Stack underflow while pop\n");
        return -1;
    }
    Node* next = stack->top->next;
    int data = stack->top->data;
    free(stack->top);
    stack->top = next;
    return data;
}

int peek(Stack* stack) {
    if(stack->top == NULL) {
        printf("Stack underflow while pop\n");
        return -1;
    }
    int data = stack->top->data;
    return data;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

int isFull(Stack* stack) {
    Node* newNode = malloc(sizeof(Node));
    if(newNode == NULL) {
        return 1;
    }
    free(newNode);
    return 0;
}

int main() {
    Stack stack = {NULL};
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    pop(&stack);
    printf("%d\n", peek(&stack));
    return 0;
}