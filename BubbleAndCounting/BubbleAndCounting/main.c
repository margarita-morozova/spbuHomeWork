#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define FIRST_TEST_SIZE 10
#define SECOND_TEST_SIZE 5

void bubble(int* pointerToArray, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (pointerToArray[j] > pointerToArray[j + 1]) {
				int temporaryPlace = pointerToArray[j];
				pointerToArray[j] = pointerToArray[j + 1];
				pointerToArray[j + 1] = temporaryPlace;
			}
		}
	}
}

int findMin(int* pointerToArray, int size) {
	int minimum = 10001;
	for (int i = 0; i < size; i++) {
		minimum = min(minimum, pointerToArray[i]);
	}

	return minimum >= 0 ? 0 : minimum;
}

void counting(int* pointerToArray, int size) {
	int minimumInArray = findMin(pointerToArray, size);
	int extreme = 10000;
	int* arrayOfNumbers = calloc(extreme, sizeof(int));

	for (int i = 0; i < size; i++) {
		arrayOfNumbers[pointerToArray[i] - minimumInArray]++;
	}

	int index = 0;
	while (index < size) {
		for (int i = 0; i < extreme; i++) {
			while (arrayOfNumbers[i + minimumInArray] > 0) {
				pointerToArray[index] = i + minimumInArray;
				arrayOfNumbers[i + minimumInArray]--;
				index++;
			}
		}
		index++;
	}

	free(arrayOfNumbers);
}

int* manualFilling(int *pointerToArray, int size) {
	printf("Enter the positive elements of your array:\n");
	for (int i = 0; i < size; i++) {
		scanf_s("%d", &pointerToArray[i]);
	}

	return pointerToArray;
}

int* randomFilling(int *pointerToArray, int size) {
	for (int i = 0; i < size; i++) {
		pointerToArray[i] = rand() % 10000;
	}

	return pointerToArray;
}

void timeCalculation(double* countingTime, double* bubbleTime) {
	int size = 100000;
	int* firstArray = (int*)calloc(size, sizeof(int));
	int* secondArray = (int*)calloc(size, sizeof(int));
	randomFilling(firstArray, size);
	memcpy(secondArray, firstArray, size);
	clock_t beginningCounting = clock();
	counting(firstArray, size);
	clock_t endingCounting = clock();
	clock_t beginningBubble = clock();
	bubble(secondArray, size);
	clock_t endingBubble = clock();

	*countingTime = (double)(endingCounting - beginningCounting) / CLOCKS_PER_SEC;
	*bubbleTime = (double)(endingBubble - beginningBubble) / CLOCKS_PER_SEC;
}

bool firstTest() {
	int firstTestArray[FIRST_TEST_SIZE] = { 0, 50, 1043, 49, 2, 0, 1, 1, 50, 33 };
	int secondTestArray[FIRST_TEST_SIZE] = { 50, 2, 1043, 49, 50, 1, 1, 0, 0, 33 };
	int sortedArray[FIRST_TEST_SIZE] = { 0, 0, 1, 1, 2, 33, 49, 50, 50, 1043 };
	bubble(firstTestArray, FIRST_TEST_SIZE);
	counting(secondTestArray, FIRST_TEST_SIZE);

	for (int i = 0; i < FIRST_TEST_SIZE; i++) {
		if (firstTestArray[i] != secondTestArray[i] || firstTestArray[i] != sortedArray[i]) {
			return false;
		}
	}

	return true;
}

bool secondTest() {
	int firstTestArray[SECOND_TEST_SIZE] = { 1000, 5, 5, 1, 1};
	int secondTestArray[SECOND_TEST_SIZE] = { 1, 5, 1, 5, 1000};
	int sortedArray[SECOND_TEST_SIZE] = { 1, 1, 5, 5, 1000 };
	bubble(firstTestArray, SECOND_TEST_SIZE);
	counting(secondTestArray, SECOND_TEST_SIZE);

	for (int i = 0; i < SECOND_TEST_SIZE; i++) {
		if (firstTestArray[i] != secondTestArray[i] || firstTestArray[i] != sortedArray[i]) {
			return false;
		}
	}

	return true;
}

int main() {
	if (!firstTest() || !secondTest()) {
		printf("Tests failed :c");
		return -1;
	}

	printf("Please, wait for the calculation to complete.\n");
	int size = 0;
	int firstDecision = 0;
	int secondDecision = 0;
	double countingTime = 0;
	double bubbleTime = 0;
	timeCalculation(&countingTime, &bubbleTime);
	printf("Time that takes to sort the array of 100000 elements using bubble sort: %f\n", bubbleTime);
	printf("Time that takes to sort the array of 100000 elements using counting sort: %f\n", countingTime);
	printf("Enter the size of your array: ");
	scanf_s("%d", &size);
	printf("\nDo you want to enter the whole array or fill it randomly?\nFor manual filling press 0\nFor automatically filling press 1\n");
	scanf_s("%d", &firstDecision);

	while (firstDecision != 0 && firstDecision != 1) {
		printf("Try again\nDo you want to enter the whole array or fill it randomly?\nFor manual filling press 0\nFor automatically filling press 1\n");
		scanf_s("%d", &firstDecision);
	}

	int* firstArray = (int*)calloc(size, sizeof(int));
	if (firstArray == NULL) {
		printf("\nmemory is not found :c");
		return -1;
	}

	if (firstDecision == 0) {
		manualFilling(firstArray, size);
	} else {
		randomFilling(firstArray, size);
	}

	printf("If you want to use bubble sort, press 0\nIf you want to use counting sort press 1\n");
	scanf_s("%d", &secondDecision);
	while (secondDecision != 0 && secondDecision != 1) {
		printf("Try again\nIf you want to use bubble sort, press 0\nIf you want to use counting sort press 1\n");
		scanf_s("%d", &secondDecision);
	}

	if (secondDecision == 0) {
		bubble(firstArray, size);
	} else {
		counting(firstArray, size);
	}

	printf("\nSorted array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", firstArray[i]);
	}

	free(firstArray);
	return 0;
}