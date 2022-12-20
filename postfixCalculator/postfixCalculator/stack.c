#include "stack.h"

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct {
    int value;
    struct Node *next;
}Node;

struct Stack{
    Node* head;
};

int push(Stack* stack, int value) {
    Node* temporary = malloc(sizeof(Node));
    if (temporary == NULL) {
        printf("No place for the value");
        return -1;
    }

    temporary->value = value;
    temporary->next = stack->head;
    stack->head = temporary;
    return 0;
}

bool isEmpty(Stack* stack) {
    return stack->head == NULL;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        return '0';
    }

    int neededValue = stack->head->value;
    Node* next = stack->head->next;
    free(stack->head);
    stack->head = next;
    return neededValue;
}

void deleteStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

int top(Stack* stack) {
    return stack->head->value;
}

Stack* createStack() {
    Stack* stack = malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}