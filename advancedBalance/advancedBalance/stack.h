#pragma once
#include <stdbool.h>

typedef struct Stack Stack;

// add one element to stack
char push(Stack* stack, char element);

// take one element from stack
char pop(Stack* stack, int* errorCode);

// is stack empty?
bool isEmpty(Stack* stack);

// create void stack
Stack* createStack(int* errorCode);

// delete the whole stack
void deleteStack(Stack* stack, int* errorCode);

// to look at the first element of stack
char top(Stack* stack, int* errorCode);