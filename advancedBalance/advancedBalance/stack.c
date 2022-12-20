#include "stack.h"

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    char value;
    struct Node* next;
}Node;

struct Stack {
    Node* head;
};

char push(Stack* stack, char value) {
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

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        return '0';
    }

    char neededValue = stack->head->value;
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

char top(Stack* stack) {
    return stack->head->value;
}

Stack* createStack() {
    Stack* stack = malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("No place for the stack");
        exit(-2);
    }
    stack->head = NULL;
    return stack;
}