#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FIRST_TEST_SIZE 7
#define SECOND_TEST_SIZE 3

int sortingStation(char expression[], char answer[], int length, int *amountOfBrackets, Stack* stack) {
	int indexOfAnswer = 0;
	for (int i = 0; i < length; i++) {
		char symbol = expression[i];
		if (symbol >= '0' && symbol <= '9') {
			answer[indexOfAnswer] = symbol;
			indexOfAnswer++;
		}
		else if (symbol == '(') {
			push(stack, symbol);
			* amountOfBrackets += 1;
		}
		else if (symbol == ')' && !isEmpty(stack)) {
			*amountOfBrackets += 1;
			char topStack = pop(stack);
			while (topStack != '(' && !isEmpty(stack)) {
				answer[indexOfAnswer] = topStack;
				topStack = pop(stack);
				indexOfAnswer++;
			}
			if (topStack != '(' && isEmpty(stack)) {
				printf("There are missing bracket");
				deleteStack(stack);
				return -1;
			}
		}
		else if (symbol == '+' || symbol == '-') {
			while (!isEmpty(stack) && (top(stack) == '+' || top(stack) == '-' || top(stack) == '*' || top(stack) == '/')) {
				answer[indexOfAnswer] = pop(stack);
				indexOfAnswer++;
			}
			push(stack, symbol);
		}
		else if (symbol == '*' || symbol == '/') {
			while (!isEmpty(stack) && (top(stack) == '*' || top(stack) == '/')) {
				answer[indexOfAnswer] = pop(stack);
				indexOfAnswer++;
			}
			push(stack, symbol);
		} else {
			printf("The expression is incorrect");
			deleteStack(stack);
			return -1;
		}
	}

	if (indexOfAnswer < (length - *amountOfBrackets) && !isEmpty(stack)) {
		for (indexOfAnswer; indexOfAnswer < length; indexOfAnswer++) {
			answer[indexOfAnswer] = pop(stack);
		}
	} else {
		return -1;
	}

	return 0;
}

bool firstTest() {
	char expression[FIRST_TEST_SIZE] = "(1+1)*2";
	Stack* stack = createStack();
	char answer[FIRST_TEST_SIZE] = "0000000";
	char rightAnswer[5] = "11+2*";
	int amountOfBrackets = 0;
	int result = sortingStation(expression, answer, FIRST_TEST_SIZE, &amountOfBrackets, stack);
	for (int i = 0; i < FIRST_TEST_SIZE - amountOfBrackets; i++) {
		if (answer[i] != rightAnswer[i]) {
			return false;
		}
	}

	return true;
}

bool secondTest() {
	char expression[SECOND_TEST_SIZE] = "2-1";
	Stack* stack = createStack();
	char answer[SECOND_TEST_SIZE] = "000";
	char rightAnswer[5] = "21-";
	int amountOfBrackets = 0;
	int result = sortingStation(expression, answer, SECOND_TEST_SIZE, &amountOfBrackets, stack);
	for (int i = 0; i < SECOND_TEST_SIZE - amountOfBrackets; i++) {
		if (answer[i] != rightAnswer[i]) {
			return false;
		}
	}

	return true;
}

int main() {
	if (!firstTest() || !secondTest()) {
		printf("There are some problems in the programm :c");
		return -1;
	}

	int length = 0;
	Stack* stack = createStack();
	printf("Enter the length of your expression: ");
	scanf_s("%d", &length);
	char* expression = calloc(length, sizeof(char));
	if (expression == NULL) {
		printf("There are problems with memory allocation");
		return -1;
	}

	printf("\nEnter your expression: ");
	scanf_s("%s", expression, (unsigned)sizeof(expression) * length);
	char* answer = calloc(length, sizeof(char));
	if (answer == NULL) {
		printf("There are problems with memory allocation");
		free(expression);
		return -1;
	}

	int amountOfBrackets = 0;
	int result = sortingStation(expression, answer, length, &amountOfBrackets, stack);
	if (result != 0) {
		deleteStack(stack);
		free(expression);
		free(answer);
		return -1;
	}

	for (int i = 0; i < (length - amountOfBrackets); i++) {
		putchar(answer[i]);
	}

	return 0;
}