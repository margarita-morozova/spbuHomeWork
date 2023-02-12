#include "stack.h"

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    char value;
    struct Node* next;
} Node;

struct Stack {
    Node* head;
};

char push(Stack* stack, char value) {
    Node* temporary = malloc(sizeof(Node));
    if (temporary == NULL) {
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

char pop(Stack* stack, int* errorCode) {
    if (isEmpty(stack)) {
        *errorCode = -1;
        return ' ';
    }

    char neededValue = stack->head->value;
    Node* next = stack->head->next;
    free(stack->head);
    stack->head = next;
    return neededValue;
}

void deleteStack(Stack* stack, int* errorCode) {
    while (!isEmpty(stack)) {
        pop(stack, &errorCode);
    }

    free(stack);
}

char top(Stack* stack, int *errorCode) {
    if (isEmpty(stack)) {
        *errorCode = -1;
        return ' ';
    }
    return stack->head->value;
}

Stack* createStack(int* errorCode) {
    Stack* stack = malloc(sizeof(Stack));
    if (stack == NULL) {
        *errorCode = -1;
        return NULL;
    }
    stack->head = NULL;
    return stack;
}