#include "binaryRepresentation.h"

#include <stdio.h>
#include <stdbool.h>

#define INT_SIZE 8
#define TWO_POWER_EIGHT 256

_Bool convertToBinTest() {
	int firstNumber = 10;
	int secondNumber = -5;
	secondNumber += TWO_POWER_EIGHT;
	int binFirstNumber[8] = {0, 0, 0, 0, 1, 0, 1, 0};
	int binSecondNumber[8] = {1, 1, 1, 1, 1, 0, 1, 1};
	int firstResult[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int secondResult[8] = {0, 0, 0, 0, 0, 0, 0, 0};

	convertToBin(firstResult, firstNumber);
	convertToBin(secondResult, secondNumber);

	for (int i = 0; i < INT_SIZE; i++) {
		if ((firstResult[i] != binFirstNumber[i]) || (secondResult[i] != binSecondNumber[i])) {
			return 0;
		}
	}

	return 1;
}

_Bool firstSumTest() {
	int binFirstNumber[8] = {0, 0, 0, 0, 1, 0, 1, 0};
	int binSecondNumber[8] = {1, 1, 1, 1, 1, 0, 1, 1};
	int sum[8] = {0, 0, 0, 0, 0, 1, 0, 1};
	int result[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	binSum(binFirstNumber, binSecondNumber, result);

	for (int i = 0; i < INT_SIZE; i++) {
		if (result[i] != sum[i]) {
			return 0;
		}
	}

	return 1;
}

_Bool secondSumTest() {
	int binFirstNumber[8] = {0, 0, 0, 0, 0, 0, 0, 1};
	int binSecondNumber[8] = {0, 0, 0, 0, 0, 0, 1, 1};
	int sum[8] = {0, 0, 0, 0, 0, 1, 0, 0};
	int result[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	binSum(binFirstNumber, binSecondNumber, result);

	for (int i = 0; i < INT_SIZE; i++) {
		if (result[i] != sum[i]) {
			return 0;
		}
	}

	return 1;
}

_Bool thirdSumTest() {
	int binFirstNumber[8] = {1, 1, 1, 1, 1, 0, 1, 1};
	int binSecondNumber[8] = {1, 1, 1, 1, 1, 0, 1, 1};
	int sum[8] = {1, 1, 1, 1, 0, 1, 1, 0};
	int result[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	binSum(binFirstNumber, binSecondNumber, result);

	for (int i = 0; i < INT_SIZE; i++) {
		if (result[i] != sum[i]) {
			return 0;
		}
	}

	return 1;
}

_Bool convertToDecTest() {
	int firstNumber = 10;
	int secondNumber = -5;
	int binFirstNumber[8] = {0, 0, 0, 0, 1, 0, 1, 0};
	int binSecondNumber[8] = {1, 1, 1, 1, 1, 0, 1, 1};
	int firstResult = convertToDec(binFirstNumber);
	int secondResult = convertToDec(binSecondNumber);

	if ((firstResult != firstNumber) || (secondResult != secondNumber)) {
		return 0;
	}

	return 1;
}