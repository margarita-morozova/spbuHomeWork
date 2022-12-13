#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INT_SIZE 8
#define TWO_POWER_EIGHT 256;

void convertToBin(int* binNumber, int number) {
	int index = INT_SIZE - 1;
	while (number > 0) {
		binNumber[index] = number & 1;
		index--;
		number = number >> 1;
	}
}

void printBin(int* number) {
	for (int i = 0; i < INT_SIZE; i++) {
		printf("%d", number[i]);
	}
}

void binSum(int* firstNumber, int* secondNumber, int* sum) {
	int addToPreviousDigit = 0;
	for (int i = INT_SIZE - 1; i >= 0; i--) {
		sum[i] = (firstNumber[i] + secondNumber[i] + addToPreviousDigit) % 2;
		if (firstNumber[i] + secondNumber[i] + addToPreviousDigit > 1) {
			addToPreviousDigit = 1;
		}
		else {
			addToPreviousDigit = 0;
		}
	}
	printBin(sum);
}

int main() {
	setlocale(LC_ALL, "ru - RU");
	system("chcp 1251");
	
	int firstNumber = 0;
	int secondNumber = 0;
	printf("¬ведите два числа: ");
	scanf_s("%d %d", &firstNumber, &secondNumber);
	int* binFirstNumber = calloc(INT_SIZE, sizeof(int));
	int* binSecondNumber = calloc(INT_SIZE, sizeof(int));
	if (firstNumber < 0) {
		firstNumber += TWO_POWER_EIGHT;
	}

	if (secondNumber < 0) {
		secondNumber += TWO_POWER_EIGHT;
	}

	convertToBin(binFirstNumber, firstNumber);
	convertToBin(binSecondNumber, secondNumber);
	printf("\nYour first number is ");
	printBin(binFirstNumber);
	printf("\nYour second number is ");
	printBin(binSecondNumber);
	int* sum = calloc(INT_SIZE, sizeof(int));
	printf("\nYour sum number is ");
	binSum(binFirstNumber, binSecondNumber, sum);

	return 0;
}