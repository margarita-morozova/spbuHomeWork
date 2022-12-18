#pragma once
#include <stdbool.h>

typedef struct Stack Stack;

int push(Stack* stack, char element); // add one element to stack

char pop(Stack* stack, int* errorCode); // take one element from stack

bool isEmpty(Stack* stack); // is stack empty?

Stack* createStack(void); // create void stack

void deleteStack(Stack* stack); // delete the whole stack

char top(Stack* stack); // to look at the first element of stack