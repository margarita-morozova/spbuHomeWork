#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

int insertionSort(int originalArray[], int beginning, int ending) {
	for (int i = beginning; i <= ending; i++) {
		for (int j = i; j >= beginning; j--) {
			if (originalArray[j] < originalArray[j - 1]) {
				int temporaryPlace = originalArray[j];
				originalArray[j] = originalArray[j - 1];
				originalArray[j - 1] = temporaryPlace;
			}
		}
	}
}

void qsort(int originalArray[], int beginning, int ending) {
	int supportElement = beginning;

	if (ending - beginning < 10) {
		insertionSort(originalArray, beginning, ending);
		return;
	}
	else {
		for (int i = beginning + 1; i <= ending; i++) {
			if (originalArray[supportElement] >= originalArray[i]) {
				int temporaryPlace = originalArray[i];
				for (int j = i; j >= supportElement; j--) {
					originalArray[j] = originalArray[j - 1];
				}

				originalArray[supportElement] = temporaryPlace;
				++supportElement;
			}
		}
	}

	qsort(originalArray, beginning, supportElement);
	qsort(originalArray, supportElement, ending);
}

bool theFirstTest() {
	int testArray[15] = { 6, 3, 5, 9, 3, 7, 4, 6, 8, 2, 5, 0, 10, -5, -8 };
	qsort(testArray, 0, 14);
	int sortedArray[15] = { -8, -5 , 0, 2, 3, 3, 4, 5, 5, 6, 6, 7, 8, 9, 10 };
	for (int i = 0; i < 15; i++) {
		if (testArray[i] != sortedArray[i]) {
			return false;
		}
	}

	return true;
}

bool theSecondTest() {
	int testArray[10] = { 3, 6, -4, -5, 2, 100, 76, 2, 10, 6 };
	qsort(testArray, 0, 9);
	int sortedArray[10] = { -5, -4, 2, 2, 3, 6, 6, 10, 76, 100 };
	for (int i = 0; i < 10; i++) {
		if (testArray[i] != sortedArray[i]) {
			return false;
		}
	}

	return true;
}

bool theThirdTest() {
	int testArray[10] = { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2 };
	qsort(testArray, 0, 9);
	int sortedArray[10] = { 1, 1, 1, 1, 1, 2, 2, 2, 2, 2 };
	for (int i = 0; i < 10; i++) {
		if (testArray[i] != sortedArray[i]) {
			return false;
		}
	}

	return true;
}

bool theFourthTest() {
	int testArray[13] = { 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	qsort(testArray, 0, 12);
	int sortedArray[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	for (int i = 0; i < 13; i++) {
		if (testArray[i] != sortedArray[i]) {
			return false;
		}
	}

	return true;
}

bool theFifthTest() {
	int testArray[9] = { 13, 12, 11, 10, 9, 8, 7, 6, 5 };
	qsort(testArray, 0, 8);
	int sortedArray[9] = { 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	for (int i = 0; i < 9; i++) {
		if (testArray[i] != sortedArray[i]) {
			return false;
		}
	}

	return true;
}

int main() {
	if (!theFirstTest() || !theSecondTest() || !theThirdTest() || !theFourthTest() || !theFirstTest()) {
		printf("There are some mistakes :c");
		return -1;
	}

	int arraySize = 0;
	printf("Enter the size of the array: ");
	scanf_s("%d", &arraySize);
	int beginning = 0;
	int ending = arraySize - 1;
	int *originalArray = (int*)malloc(arraySize * sizeof(int));

	if (originalArray == NULL) {
		printf("There are some problems with memory allocation");
		return -1;
	}

	printf("Fill the array: ");
	for (int i = 0; i < arraySize; i++) {
		scanf_s("%d", &originalArray[i]);
	}

	qsort(originalArray, beginning, ending);
	for (int i = 0; i < arraySize; i++) {
		printf("%d ", originalArray[i]);
	}

	free(originalArray);
	return 0;
}