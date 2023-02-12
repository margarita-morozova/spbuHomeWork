#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 101
#define WRONG_TEST_SIZE 6
#define FIRST_TEST_SIZE 10
#define SECOND_TEST_SIZE 8

int evaluateExpression(char expression[], int length, int* errorCode) {
    Stack* stack = createStack(&errorCode);
    if (*errorCode != 0) {
        printf("There are problems with memory allocation");
        return -1;
    }

    for (int i = 0; i < length; i++) {
        char symbol = expression[i];
        if (symbol == ' ') {
            continue;
        }
        bool isInSet = (symbol >= '0' && symbol <= '9');
        if (isInSet) {
            push(stack, symbol - '0');
        } else {
            if (isEmpty(stack)) {
                printf("\nYou didn't add number");
                *errorCode = -1;
                deleteStack(stack, &errorCode);
                return 0;
            }

            int firstNumber = pop(stack, &errorCode);
            if (*errorCode != 0) {
                return -1;
            }
            if (isEmpty(stack)) {
                printf("\nYou didn't add the second number");
                *errorCode = -2;
                deleteStack(stack, &errorCode);
                return -1;
            }

            int secondNumber = pop(stack, &errorCode);
            if (*errorCode != 0) {
                return -1;
            }
            if (symbol == '*') {
                if (push(stack, secondNumber * firstNumber) != 0) {
                    printf("No place for the value");
                }
            }
            else if (symbol == '/') {
                if (push(stack, secondNumber / firstNumber) != 0) {
                    printf("No place for the value");
                }
            }
            else if (symbol == '-') {
                if (push(stack, secondNumber - firstNumber) != 0) {
                    printf("No place for the value");
                }
            }
            else if (symbol == '+') {
                if (push(stack, secondNumber + firstNumber) != 0) {
                    printf("No place for the value");
                }
            } else {
                *errorCode = -3;
                deleteStack(stack, &errorCode);
                return 0;
            }
        }
    }

    if (!isEmpty(stack)) {
        char answer = pop(stack, &errorCode);
        deleteStack(stack, &errorCode);
        return answer;
    }
    else {
        free(stack);
        return - 1;
    }
}

bool wrongDataTest() {
    int length = WRONG_TEST_SIZE - 1;
    char expression[WRONG_TEST_SIZE] = "74]6-";
    int errorCode = 0;
    int result = evaluateExpression(expression, length, &errorCode);
    return errorCode == -3 && result == 0;
}

bool firstCorrectDataTest() {
    int length = FIRST_TEST_SIZE - 1;
    char expression[FIRST_TEST_SIZE] = "96+2*3/2-";
    int errorCode = 0;
    int result = evaluateExpression(expression, length, &errorCode);
    if (errorCode != 0 || result != 8) {
        return false;
    }

    return true;
}

bool secondCorrectDataTest() {
    int length = SECOND_TEST_SIZE - 1;
    char expression[SECOND_TEST_SIZE] = "96-12+*";
    int errorCode = 0;
    int result = evaluateExpression(expression, length, &errorCode);
    if (errorCode != 0 || result != 9) {
        return false;
    }

    return true;
}

int main() {
    if (!wrongDataTest() || !firstCorrectDataTest() || !secondCorrectDataTest()) {
        printf("\nThere are some problems in the program :c");
        return -1;
    }

    int length = 0;
    int errorCode = 0;
    char expression[MAX_LENGTH] = "";
    printf("Enter the expression: ");
    fgets(expression, MAX_LENGTH, stdin);
    length = (int)strlen(expression) - 1;
    int result = evaluateExpression(expression, length, &errorCode);
    if (errorCode == -3) {
        printf("Failed to recognize the symbol :c");
        return -1;
    }
    else if (errorCode != 0) {
        return -1;
    }

    printf("\nThe result of the expression is: %d", result);
    return 0;
}