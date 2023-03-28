#include "stack.h"

#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define FIRST_TEST_LENGTH 6
#define SECOND_TEST_LENGTH 7
#define MAX_LENGTH 101

int evaluateExpression(char expression[], int length, int *errorCode) {
    Stack* stack = createStack(&errorCode);
    for (int i = 0; i < length; i++) {
        char element = expression[i];
        if (element == '{' || element == '(' || element == '[') {
            push(stack, element);
        }
        else if (element == '}' || element == ')' || element == ']') {
            if (isEmpty(stack)) {
                deleteStack(stack, &errorCode);
                return -1;
            }

            char previousElement = pop(stack, &errorCode);
            if (*errorCode != 0) {
                return -1;
            }

            if (previousElement == '(' && element != ')') {
                deleteStack(stack, &errorCode);
                return -1;
            }
            else if (previousElement == '{' && element != '}') {
                deleteStack(stack, &errorCode);
                return -1;
            }
            else if (previousElement == '[' && element != ']') {
                deleteStack(stack, &errorCode);
                return -1;
            }
        }
        else {
            deleteStack(stack, &errorCode);
            return -2;
        }
    }

    if (!isEmpty(stack)) {
        deleteStack(stack, &errorCode);
        return -1;
    }

    deleteStack(stack, &errorCode);
    return 0;
}

bool rightBalanceTest() {
    int errorCode = 0;
    char expression[FIRST_TEST_LENGTH + 1] = "({[]})\0";
    return (evaluateExpression(expression, FIRST_TEST_LENGTH, &errorCode) == 0);
}

bool wrongBalanceTest() {
    char expression[SECOND_TEST_LENGTH + 1] = "(())[]{\0";
    int errorCode = 0;
    return (evaluateExpression(expression, SECOND_TEST_LENGTH, &errorCode) != 0);
}

int main() {
    if (!rightBalanceTest() || !wrongBalanceTest()) {
        printf("There are some problems in the programm :c");
        return -1;
    }
    int errorCode = 0;
    char expression[MAX_LENGTH] = "";
    printf("Enter the expression: ");
    fgets(expression, MAX_LENGTH, stdin);
    int length = strlen(expression) - 1;
    int result = evaluateExpression(expression, length, &errorCode);
    if (result == -1) {
        printf("Wrong bracket balance");
    }
    else if (result == -2) {
        printf("Failed to identify the symbol");
    }
    else {
        printf("Right bracket balance!");
    }

    return 0;
}