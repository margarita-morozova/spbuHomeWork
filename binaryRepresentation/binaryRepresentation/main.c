#include "binaryRepresentation.h"

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

#define INT_SIZE 8
#define TWO_POWER_EIGHT 256;

int main() {
	setlocale(LC_ALL, "ru - RU");
	system("chcp 1251");
	
	int firstNumber = 0;
	int secondNumber = 0;
	printf("Введите два числа из диапазона [-128; 127]: ");
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
	printf("\nВаше первое число: ");
	printBin(binFirstNumber);
	printf("\nВаше второе число: ");
	printBin(binSecondNumber);
	int* sum = calloc(INT_SIZE, sizeof(int));
	printf("\nСумма ваших чисел в двоичной системе счисления: ");
	binSum(binFirstNumber, binSecondNumber, sum);
	int decSum = convertToDec(sum);
	printf("\nДесятичное представление суммы: %d", decSum);

	return 0;
}