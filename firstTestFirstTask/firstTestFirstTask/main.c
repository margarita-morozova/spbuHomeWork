#include "convertToDec.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 5

_Bool firstTest() {
	int number[3] = {1, 0, 1};
	int rightAnswer[LENGTH] = {0, 0, 0, 0, 5};
	int* answer = (int*)calloc(LENGTH, sizeof(int));
	if (answer == NULL) {
		printf("There is not enough memory :c");
		return -1;
	}

	int decAnswer = convertToDec(number, 3);
	convertToString(answer, decAnswer);
	for (int i = 0; i < LENGTH; i++) {
		if (answer[i] != rightAnswer[i]) {
			return 0;
		}
	}

	return 1;
}

_Bool secondTest() {
	int number[LENGTH] = { 1, 0, 1, 0, 0 };
	int rightAnswer[LENGTH] = { 0, 0, 0, 2, 0 };
	int* answer = (int*)calloc(LENGTH, sizeof(int));
	if (answer == NULL) {
		printf("There is not enough memory :c");
		return -1;
	}

	int decAnswer = convertToDec(number, 5);
	convertToString(answer, decAnswer);
	for (int i = 0; i < LENGTH; i++) {
		if (answer[i] != rightAnswer[i]) {
			return 0;
		}
	}

	return 1;
}

_Bool thirdTest() {
	int number[1] = { 0 };
	int rightAnswer[LENGTH] = { 0, 0, 0, 0, 0 };
	int* answer = (int*)calloc(LENGTH, sizeof(int));
	if (answer == NULL) {
		printf("There is not enough memory :c");
		return -1;
	}

	int decAnswer = convertToDec(number, 1);
	convertToString(answer, decAnswer);
	for (int i = 0; i < LENGTH; i++) {
		if (answer[i] != rightAnswer[i]) {
			return 0;
		}
	}

	return 1;
}

int main() {
	if (!firstTest() || !secondTest() || !thirdTest()) {
		printf("Something goes wrong :c");
		return -1;
	}

	int size = 0;
	printf("Enter the length of your string: ");
	scanf_s("%d", &size);
	int* yourNumber = (int*)calloc(size, sizeof(int));
	if (yourNumber == NULL) {
		printf("There is not enough memory :c");
		return -1;
	}

	int* answer = (int*)calloc(LENGTH, sizeof(int));
	if (answer == NULL) {
		printf("There is not enough memory :c");
		return -1;
	}

	printf("Enter your string (separating the numbers with spaces): ");
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &yourNumber[i]);
	}

	int decNumber = convertToDec(yourNumber, size);
	convertToString(answer, decNumber);
	printf("\nYour string is: ");
	for (int i = 0; i < LENGTH; i++) {
		printf("%d", answer[i]);
	}

	return 0;
}