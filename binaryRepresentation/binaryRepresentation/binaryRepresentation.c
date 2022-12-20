#include <stdio.h>
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
}

int convertToDec(int* number) {
	if (number[0] == 1) {
		if (number[INT_SIZE - 1] == 1) {
			number[INT_SIZE - 1] = 0;
		}
		else {
			int index = INT_SIZE - 1;
			while (number[index] != 1) {
				index--;
			}

			for (int i = index; i < INT_SIZE - 1; i++) {
				number[i] ^= 1;
			}
			number[INT_SIZE - 1] = 1;
		}
	}
	int sum = 0;
	for (int i = INT_SIZE - 1; i >= 0; i--) {
		if (number[i] == 1)
		{
			sum += pow(2, INT_SIZE - 1 - i);
		}
	}
	if (sum > 127) {
		sum -= TWO_POWER_EIGHT;
		sum += 1;
	}

	return sum;
}