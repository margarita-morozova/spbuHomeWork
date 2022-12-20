#include "stack.h"

#include <stdio.h>
#include <malloc.h>


#define FIRST_TEST_LENGTH 6
#define SECOND_TEST_LENGTH 7

int evaluateExpression(char expression[], int length, Stack* stack) {
    for (int i = 0; i < length; i++) {
        char element = expression[i];
        if (element == '{' || element == '(' || element == '[') {
            push(stack, element);
        }
        else if (element == '}' || element == ')' || element == ']') {
            if (isEmpty(stack)) {
                deleteStack(stack);
                return -1;
            }

            char previousElement = pop(stack);
            if (previousElement == '(' && element != ')') {
                deleteStack(stack);
                return -1;
            }
            else if (previousElement == '{' && element != '}') {
                deleteStack(stack);
                return -1;
            }
            else if (previousElement == '[' && element != ']') {
                deleteStack(stack);
                return -1;
            }
        }
        else {
            deleteStack(stack);
            return -2;
        }
    }

    if (!isEmpty(stack)) {
        deleteStack(stack);
        return -1;
    }

    deleteStack(stack);
    return 0;
}

bool rightBalanceTest() {
    Stack* stack = createStack();
    char expression[FIRST_TEST_LENGTH + 1] = "({[]})";
    return (evaluateExpression(expression, FIRST_TEST_LENGTH, stack) == 0);
}

bool wrongBalanceTest() {
    Stack* stack = createStack();
    char expression[SECOND_TEST_LENGTH + 1] = "(())[]{";
    return (evaluateExpression(expression, SECOND_TEST_LENGTH, stack) != 0);
}

int main() {
    if (!rightBalanceTest() || !wrongBalanceTest()) {
        printf("There are some problems in the programm :c");
        return -1;
    }

    int length = 0;
    Stack* stack = createStack();
    printf("Enter the number of brackets: ");
    scanf_s("%d", &length);
    char* expression = (char*)malloc(length * sizeof(char) + 1);
    printf("\nEnter the a set of brackets without spaces:");
    scanf_s("%s", expression, (unsigned)sizeof(expression) * length);
    int result = evaluateExpression(expression, length, stack);
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