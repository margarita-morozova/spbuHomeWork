#include <stdio.h>
#include <math.h>

#define LENGTH 5

int convertToDec(int* number, int size) {
	int sum = 0;
	for (int i = size - 1; i >= 0; i--) {
		if (number[i] == 1)
		{
			sum += pow(2, size - 1 - i);
		}
	}

	return sum;
}

void convertToString(int* string, int number) {
	int index = LENGTH - 1;
	while (number > 0) {
		string[index] = number % 10;
		number /= 10;
		--index;
	}
}