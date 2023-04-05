#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FIRST_TEST_ARRAY_SIZE 10
#define SECOND_TEST_ARRAY_SIZE 9
#define THIRD_TEST_ARRAY_SIZE 6

void qSort(int* originalArray, int size, int beginning, int ending) {
	int supportElement = beginning;
	for (int i = beginning + 1; i < ending + 1; i++) {
		if (originalArray[supportElement] > originalArray[i]) {
			int temporaryPlace = originalArray[i];
			for (int j = i; j >= supportElement; j--) {
				originalArray[j] = originalArray[j - 1];
			}

			originalArray[supportElement] = temporaryPlace;
			++supportElement;
		}
	}

	if (supportElement - beginning > 0) {
		qSort(originalArray, supportElement - beginning, beginning, supportElement - 1);
	}

	if (ending - supportElement > 0) {
		qSort(originalArray, ending - supportElement, supportElement + 1, ending);
	}
}

int theMostFrequentElement(int *pointerToArray, int size) {
	int neededElement = -100;
	int numberOfTheElement = 0;
	int count = 1;
	for (int i = 1; i < size; i++) {
		if (pointerToArray[i] == pointerToArray[i - 1]) {
			++count;
		}
		else {
			if (count > numberOfTheElement) {
				numberOfTheElement = count;
				neededElement = pointerToArray[i - 1];
			}

			count = 1;
		}
	}

	if (count > numberOfTheElement) {
		numberOfTheElement = count;
		neededElement = pointerToArray[size - 1];
	}

	return neededElement;
}

int* randomFilling(int* pointerToArray, int size) {
	for (int i = 0; i < size; i++) {
		pointerToArray[i] = rand() % 100;
	}

	return pointerToArray;
}

bool firstTest() {
	int testArray[FIRST_TEST_ARRAY_SIZE] = { 5, 5, 3, 4, 2, 8, 8, 9, 8, 0 };
	int rightArray[FIRST_TEST_ARRAY_SIZE] = { 0, 2, 3, 4, 5, 5, 8, 8, 8, 9 };
	int answer = 8;
	qSort(testArray, FIRST_TEST_ARRAY_SIZE, 0, FIRST_TEST_ARRAY_SIZE - 1);
	for (int i = 0; i < FIRST_TEST_ARRAY_SIZE; i++) {
		if (testArray[i] != rightArray[i]) {
			return false;
		}
	}

	return theMostFrequentElement(testArray, FIRST_TEST_ARRAY_SIZE) == answer;
}

bool secondTest() {
	int testArray[SECOND_TEST_ARRAY_SIZE] = { 8, 8, 8, 5, 5, 5, 4, 0, 9 };
	int rightArray[SECOND_TEST_ARRAY_SIZE] = { 0, 4, 5, 5, 5, 8, 8, 8, 9 };
	int answer = 5;
	qSort(testArray, SECOND_TEST_ARRAY_SIZE, 0, SECOND_TEST_ARRAY_SIZE - 1);
	for (int i = 0; i < SECOND_TEST_ARRAY_SIZE; i++) {
		if (testArray[i] != rightArray[i]) {
			return false;
		}
	}

	return theMostFrequentElement(testArray, SECOND_TEST_ARRAY_SIZE) == answer;
}

bool thirdTest() {
	int testArray[THIRD_TEST_ARRAY_SIZE] = { 1, 2, 2, 3, 3, 3 };
	int rightArray[THIRD_TEST_ARRAY_SIZE] = { 1, 2, 2, 3, 3, 3 };
	int answer = 3;
	qSort(testArray, THIRD_TEST_ARRAY_SIZE, 0, THIRD_TEST_ARRAY_SIZE - 1);
	for (int i = 0; i < THIRD_TEST_ARRAY_SIZE; i++) {
		if (testArray[i] != rightArray[i]) {
			return false;
		}
	}

	return theMostFrequentElement(testArray, THIRD_TEST_ARRAY_SIZE) == answer;
}

int main() {
	if (!firstTest() || !secondTest() || !thirdTest()) {
		printf("There are some mistakes in the programm :c\n");
		return -1;
	}

	int size = 0;
	printf("Enter the size of the array: ");
	scanf_s("%d", &size);
	while (size < 1) {
		printf("The size of the array has to be positive number\n");
		printf("Enter the size of the array: ");
		scanf_s("%d", &size);
	}

	int* firstArray = (int*)calloc(size, sizeof(int));
	if (firstArray == NULL) {
		printf("\nmemory is not found :c");
		return -1;
	}

	randomFilling(firstArray, size);
	printf("Your array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", firstArray[i]);
	}

	qSort(firstArray, size, 0, size - 1);
	printf("\nThe most frequent element in your array is %d", theMostFrequentElement(firstArray, size));
	free(firstArray);
	return 0;
}