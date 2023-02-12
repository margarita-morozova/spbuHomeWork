#include "sorting.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FIRST_TEST_ARRAY_SIZE 10
#define SECOND_TEST_ARRAY_SIZE 9
#define THIRD_TEST_ARRAY_SIZE 1
#define FOURTH_TEST_ARRAY_SIZE 6

int theMostFrequentElement(int* pointerToArray, int size) {
	int neededElement = -100;
	int numberOfTheElement = 0;
	int count = 1;

	if (size == 1) {
		return pointerToArray[0];
	}

	for (int i = 1; i < size; i++) {
		if (pointerToArray[i] == pointerToArray[i - 1]) {
			++count;
		}

		if (count > numberOfTheElement) {
			numberOfTheElement = count;
			neededElement = pointerToArray[i - 1];
			if (i == (size - 1) || pointerToArray[i] != pointerToArray[i + 1]) {
				count = 1;
			}
		}
	}

	return neededElement;
}

bool firstTest() {
	int testArray[FIRST_TEST_ARRAY_SIZE] = { 5, 5, 3, 4, 2, 8, 8, 9, 8, 0 };
	int rightArray[FIRST_TEST_ARRAY_SIZE] = { 0, 2, 3, 4, 5, 5, 8, 8, 8, 9 };
	int answer = 8;
	qSort(testArray, FIRST_TEST_ARRAY_SIZE);
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
	qSort(testArray, SECOND_TEST_ARRAY_SIZE);
	for (int i = 0; i < SECOND_TEST_ARRAY_SIZE; i++) {
		if (testArray[i] != rightArray[i]) {
			return false;
		}
	}

	return theMostFrequentElement(testArray, SECOND_TEST_ARRAY_SIZE) == answer;
}

bool thirdTest() {
	int testArray[THIRD_TEST_ARRAY_SIZE] = { 4 };
	int rightArray[THIRD_TEST_ARRAY_SIZE] = { 4 };
	int answer = 4;
	qSort(testArray, THIRD_TEST_ARRAY_SIZE);
	for (int i = 0; i < THIRD_TEST_ARRAY_SIZE; i++) {
		if (testArray[i] != rightArray[i]) {
			return false;
		}
	}

	return theMostFrequentElement(testArray, THIRD_TEST_ARRAY_SIZE) == answer;
}

bool fourthTest() {
	int testArray[FOURTH_TEST_ARRAY_SIZE] = { 1, 2, 2, 3, 3, 3 };
	int rightArray[FOURTH_TEST_ARRAY_SIZE] = { 1, 2, 2, 3, 3, 3 };
	int answer = 3;
	qSort(testArray, FOURTH_TEST_ARRAY_SIZE);
	for (int i = 0; i < FOURTH_TEST_ARRAY_SIZE; i++) {
		if (testArray[i] != rightArray[i]) {
			return false;
		}
	}

	return theMostFrequentElement(testArray, FOURTH_TEST_ARRAY_SIZE) == answer;
}

int main()
{
	if (!firstTest() || !secondTest() || !thirdTest() || !fourthTest()) {
		printf("There are some mistakes in the programm :c\n");
		return -1;
	}

	FILE* file = NULL;
	fopen_s(&file, "..\\testFile.txt", "r");
	if (file == NULL) {
		printf("file not found!");
		fclose(file);
		return -1;
	}

	int size = 0;
	fscanf_s(file, "%d", &size);

	if (size < 1) {
		printf("\nThe wrong data in the file\n");
		fclose(file);
		return -1;
	}

	int* firstArray = (int*)calloc(size, sizeof(int));
	if (firstArray == NULL) {
		printf("\nmemory is not found :c");
		fclose(file);
		return -1;
	}

	for (int i = 0; i < size; i++) {
		fscanf_s(file, "%d", &firstArray[i]);
	}

	printf("Your array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", firstArray[i]);
	}

	qSort(firstArray, size);
	printf("\nThe most frequent element in your array is %d", theMostFrequentElement(firstArray, size));
	free(firstArray);
	fclose(file);
	return 0;
}