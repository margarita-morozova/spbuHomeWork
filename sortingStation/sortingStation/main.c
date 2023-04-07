#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 101
#define FIRST_TEST_SIZE 7
#define SECOND_TEST_SIZE 3

int sortingStation(char expression[], char answer[]) {
	int errorCode = 0;
	int length = (int)strlen(expression);
	int amountOfBrackets = 0;
	Stack* stack = createStack(&errorCode);
	if (errorCode != 0) {
		return -2;
	}

	int indexOfAnswer = 0;
	for (int i = 0; i < length; i++) {
		char symbol = expression[i];
		if (symbol >= '0' && symbol <= '9') {
			answer[indexOfAnswer] = symbol;
			indexOfAnswer++;
		}
		else if (symbol == '(') {
			push(stack, symbol);
			++amountOfBrackets;
		}
		else if (symbol == ')' && !isEmpty(stack)) {
			char topStack = pop(stack, &errorCode);
			if (errorCode != 0) {
				return -1;
			}

			while (topStack != '(' && !isEmpty(stack)) {
				answer[indexOfAnswer] = topStack;
				topStack = pop(stack, &errorCode);
				if (errorCode != 0) {
					return -1;
				}

				++indexOfAnswer;
				++amountOfBrackets;
			}

			if (topStack != '(' && isEmpty(stack)) {
				deleteStack(stack, &errorCode);
				return -1;
			}
		}
		else if (symbol == '+' || symbol == '-') {
			while (!isEmpty(stack) && (top(stack, &errorCode) == '+' || top(stack, &errorCode) == '-' || top(stack, &errorCode) == '*' || top(stack, &errorCode) == '/')) {
				if (errorCode != 0) {
					return -1;
				}

				answer[indexOfAnswer] = pop(stack, &errorCode);
				indexOfAnswer++;
			}
			push(stack, symbol);
		}
		else if (symbol == '*' || symbol == '/') {
			while (!isEmpty(stack) && (top(stack, &errorCode) == '*' || top(stack, &errorCode) == '/')) {
				if (errorCode != 0) {
					return -1;
				}
				
				answer[indexOfAnswer] = pop(stack, &errorCode);
				if (errorCode != 0) {
					return -1;
				}

				indexOfAnswer++;
			}
			push(stack, symbol);
		} else {
			deleteStack(stack, &errorCode);
			return -1;
		}
	}

	if (indexOfAnswer < (length - amountOfBrackets) && !isEmpty(stack)) {
		for (indexOfAnswer; indexOfAnswer < length - amountOfBrackets; ++indexOfAnswer) {
			answer[indexOfAnswer] = pop(stack, &errorCode);
			if (errorCode != 0) {
				return -1;
			}
		}
	} else {
		return -1;
	}

	answer[length - amountOfBrackets] = '\0';
	deleteStack(stack, &errorCode);
	return 0;
}

bool firstTest() {
	char expression[FIRST_TEST_SIZE + 1] = "(1+1)*2";
	char answer[FIRST_TEST_SIZE + 1] = "";
	char rightAnswer[FIRST_TEST_SIZE - 2] = "11+2*";
	int amountOfBrackets = 2;
	int result = sortingStation(expression, answer);
	for (int i = 0; i < FIRST_TEST_SIZE - amountOfBrackets; i++) {
		if (answer[i] != rightAnswer[i]) {
			return false;
		}
	}

	return true;
}

bool secondTest() {
	char expression[SECOND_TEST_SIZE + 1] = "2-1";
	char answer[SECOND_TEST_SIZE + 1] = "";
	char rightAnswer[SECOND_TEST_SIZE] = "21-";
	int result = sortingStation(expression, answer);
	for (int i = 0; i < SECOND_TEST_SIZE; i++) {
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

	char expression[MAX_SIZE] = "";
	printf("Enter your expression: ");
	fgets(expression, MAX_SIZE, stdin);
	char answer[MAX_SIZE] = "";;
	expression[(int)strlen(expression) - 1] = '\0';
	int result = sortingStation(expression, answer);
	if (result == -1) {
		printf("\nThe expression is wrong.");
		return -1;
	} else if (result == -2) {
		printf("\nThere are problems with memory allocation.");
		return -1;
	}

	printf("\nThe answer is: %s", answer);
	return 0;
}