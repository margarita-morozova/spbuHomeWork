#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define firstTestSize 10
#define secondTestSize 5
#define thirdTestSize 2
#define fourthTestSize 4

int* halfQSort(int* pointerToArray, int size)
{
	int indexOfSupportElement = 0;
	int supportElement = pointerToArray[indexOfSupportElement];
	int leftIndex = 1;
	int rightIndex = size - 1;
	while (leftIndex < rightIndex) {
		while (pointerToArray[leftIndex] < supportElement) {
			++leftIndex;
		}

		while (pointerToArray[rightIndex] >= supportElement) {
			--rightIndex;
		}

		if (leftIndex >= rightIndex) {
			break;
		}

		if (pointerToArray[leftIndex] >= supportElement && pointerToArray[rightIndex] < supportElement) {
			int temporaryPlace = pointerToArray[leftIndex];
			pointerToArray[leftIndex] = pointerToArray[rightIndex];
			pointerToArray[rightIndex] = temporaryPlace;
		}
	}

	if (pointerToArray[leftIndex] >= supportElement) {
		--leftIndex;
	}
	
	pointerToArray[indexOfSupportElement] = pointerToArray[leftIndex];
	pointerToArray[leftIndex] = supportElement;

	return pointerToArray;
}

int* randomFilling(int* pointerToArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		pointerToArray[i] = rand() % 100;
	}

	return pointerToArray;
}

bool test(int size)
{
	int* testArray = (int*)calloc(size, sizeof(int));
	if (testArray == NULL)
	{
		return -1;
	}

	randomFilling(testArray, size);
	int supportElement = testArray[0];
	bool isRightPartCorrect = false;
	halfQSort(testArray, size);
	for (int i = 0; i < size; i++)
	{
		if (testArray[i] >= supportElement) {
			isRightPartCorrect = true;
		}

		if (isRightPartCorrect && testArray[i] < supportElement) {
			isRightPartCorrect = false;
		}
	}

	free(testArray);
	return isRightPartCorrect;
}

int main()
{
	if (!test(10) || !test(5) || !test(2) || !test(4))
	{
		printf("Tests failed :c");
		return -1;
	}

	int size = 0;
	printf("Enter the size of the array: ");
	scanf_s("%d", &size);
	int* firstArray = (int*)calloc(size, sizeof(int));
	if (firstArray == NULL)
	{
		printf("\nmemory is not found :c");
		return -1;
	}

	randomFilling(firstArray, size);
	printf("\nYour array: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", firstArray[i]);
	}

	halfQSort(firstArray, size);
	printf("\nHalf-sorted array: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", firstArray[i]);
	}
	
	free(firstArray);
	return 0;
}