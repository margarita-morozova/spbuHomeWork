#include "stack.h"

#include <stdio.h>
#include <malloc.h>

int evaluateExpression(char expression[], int length, Stack* stack) {
    for (int i = 0; i < length; i++) {
        char element = expression[i];
        printf("%c", element);
        if (element == '{' || element == '(' || element == '[') {
            push(stack, element);
        }
        else if (element == ')' && !isEmpty(stack)) {
            if (pop(stack) != '(') {
                deleteStack(stack);
                return -1;
            }
        }
        else if (element == '}' && !isEmpty(stack)) {
            if (pop(stack) != '{') {
                deleteStack(stack);
                return -1;
            }
        }
        else if (element == ']' && !isEmpty(stack)) {
            if (pop(stack) != '[') {
                deleteStack(stack);
                return -1;
            }
        } 
        else if (isEmpty(stack)) {
            deleteStack(stack);
            return -1;
        } else {
            deleteStack(stack);
            return -2;
        }
    }

    return 0;
}

int main() {
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