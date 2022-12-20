#include "stack.h"

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define WRONG_TEST_SIZE 6
#define FIRST_TEST_SIZE 10
#define SECOND_TEST_SIZE 8

int evaluateExpression(char expression[], int length, Stack* stack, int* errorCode) {
    for (int i = 0; i < length; i++) {
        char symbol = expression[i];
        bool isInSet = (symbol >= '0' && symbol <= '9');
        if (isInSet) {
            push(stack, symbol - '0');
        }
        else {
            if (isEmpty(stack)) {
                printf("\nYou didn't add number");
                *errorCode = -1;
                deleteStack(stack);
                return 0;
            }

            int firstNumber = pop(stack);
            if (isEmpty(stack)) {
                printf("\nYou didn't add the second number");
                *errorCode = -2;
                deleteStack(stack);
                return -0;
            }

            int secondNumber = pop(stack);
            if (symbol == '*') {
                push(stack, secondNumber * firstNumber);
            }
            else if (symbol == '/') {
                push(stack, secondNumber / firstNumber);
            }
            else if (symbol == '-') {
                push(stack, secondNumber - firstNumber);
            }
            else if (symbol == '+') {
                push(stack, secondNumber + firstNumber);
            }
            else {
                *errorCode = -3;
                deleteStack(stack);
                return 0;
            }
        }
    }
    return pop(stack);
}

bool wrongDataTest() {
    int length = WRONG_TEST_SIZE - 1;
    char expression[WRONG_TEST_SIZE] = "74]6-";
    int errorCode = 0;
    Stack* stack = createStack();
    int result = evaluateExpression(expression, length, stack, &errorCode);
    if (errorCode != -3 || result != 0) {
        return false;
    }

    return true;
}

bool firstCorrectDataTest() {
    int length = FIRST_TEST_SIZE - 1;
    char expression[FIRST_TEST_SIZE] = "96+2*3/2-";
    int errorCode = 0;
    Stack* stack = createStack();
    int result = evaluateExpression(expression, length, stack, &errorCode);
    if (errorCode != 0 || result != 8) {
        return false;
    }

    deleteStack(stack);
    return true;
}

bool secondCorrectDataTest() {
    int length = SECOND_TEST_SIZE - 1;
    char expression[SECOND_TEST_SIZE] = "96-12+*";
    int errorCode = 0;
    Stack* stack = createStack();
    int result = evaluateExpression(expression, length, stack, &errorCode);
    if (errorCode != 0 || result != 9) {
        return false;
    }

    deleteStack(stack);
    return true;
}

int main() {
    if (!wrongDataTest() || !firstCorrectDataTest() || !secondCorrectDataTest()) {
        printf("\nThere are some problems in the programm :c");
        return -1;
    }

    int length = 0;
    int errorCode = 0;
    Stack *stack = createStack();
    printf("Enter the number of symbols: ");
    scanf_s("%d", &length);
    char* expression = (char*)malloc(length * sizeof(char) + 1);
    printf("\nEnter the expression without spaces:");
    scanf_s("%s", expression, (unsigned)sizeof(expression)*length);
    int result = evaluateExpression(expression, length, stack, &errorCode);
    if (errorCode == -3) {
        printf("Failed to recognize the symbol :c");
        return -1;
    }
    else if (errorCode != 0) {
        return -1;
    }

    printf("\nThe result of the expression is: %d", result);
    deleteStack(stack);
	return 0;
}