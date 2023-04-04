#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define FIRST_TEST_ARRAY_SIZE 10
#define SECOND_TEST_ARRAY_SIZE 7
#define THIRD_TEST_ARRAY_SIZE 10
#define FOURTH_TEST_ARRAY_SIZE 9
#define FIFTH_TEST_ARRAY_SIZE 10

void qSort(int *originalArray, int size, int beginning, int ending)
{
	int supportElement = beginning;
	for (int i = beginning + 1; i < ending + 1; i++)
	{
		if (originalArray[supportElement] > originalArray[i])
		{
			int temporaryPlace = originalArray[i];
			for (int j = i; j >= supportElement; j--)
			{
				originalArray[j] = originalArray[j - 1];
			}

			originalArray[supportElement] = temporaryPlace;
			++supportElement;
		}
	}

	if (supportElement - beginning > 0)
	{
		qSort(originalArray, supportElement - beginning, beginning, supportElement - 1);
	}

	if (ending - supportElement > 0)
	{
		qSort(originalArray, ending - supportElement, supportElement + 1, ending);
	}
}

bool binarySearch(int *sortedArray, int beginning, int ending, int number)
{
	const int middle = (ending + beginning) / 2;

	if (beginning <= ending) {
		if (sortedArray[middle] == number)
		{
			return true;
		}

		if (sortedArray[middle] > number)
		{
			return binarySearch(sortedArray, beginning, middle - 1, number);
		}

		return binarySearch(sortedArray, middle + 1, ending, number);
	}

	return false;
}

int* randomFilling(int* pointerToArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		pointerToArray[i] = rand() % 10000;
	}

	return pointerToArray;
}

bool firstTestSorting()
{
	int testArray[FIRST_TEST_ARRAY_SIZE] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int rightArray[FIRST_TEST_ARRAY_SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	qSort(testArray, FIRST_TEST_ARRAY_SIZE, 0, FIRST_TEST_ARRAY_SIZE - 1);
	for (int i = 0; i < FIRST_TEST_ARRAY_SIZE; i++)
	{
		if (testArray[i] != rightArray[i])
		{
			return false;
		}
	}

	return true;
}

bool secondTestSorting()
{
	int testArray[SECOND_TEST_ARRAY_SIZE] = {4, 6, 3, 5, 2, 1, 7};
	int rightArray[SECOND_TEST_ARRAY_SIZE] = { 1, 2, 3, 4, 5, 6, 7};
	qSort(testArray, SECOND_TEST_ARRAY_SIZE, 0, SECOND_TEST_ARRAY_SIZE - 1);
	for (int i = 0; i < SECOND_TEST_ARRAY_SIZE; i++)
	{
		if (testArray[i] != rightArray[i])
		{
			return false;
		}
	}

	return true;
}

bool firstTestSearching()
{
	int testArray[THIRD_TEST_ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int neededNumber = 9;
	return binarySearch(testArray, 0, THIRD_TEST_ARRAY_SIZE - 1, neededNumber);
}

bool secondTestSearching()
{
	int testArray[FOURTH_TEST_ARRAY_SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8};
	int neededNumber = 9;
	return !binarySearch(testArray, 0, FOURTH_TEST_ARRAY_SIZE - 1, neededNumber);
}

bool testOfBothFunctions()
{
	int testArray[FIFTH_TEST_ARRAY_SIZE] = {8, 3, 2, 1, 4, 5, 6, 7, 0, 9};
	int rightArray[FIFTH_TEST_ARRAY_SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int neededNumber = 9;
	qSort(testArray, FIFTH_TEST_ARRAY_SIZE, 0, FIFTH_TEST_ARRAY_SIZE - 1);
	for (int i = 0; i < FIFTH_TEST_ARRAY_SIZE; i++)
	{
		if (testArray[i] != rightArray[i])
		{
			return false;
		}
	}

	if (!binarySearch(testArray, 0, FIFTH_TEST_ARRAY_SIZE, neededNumber))
	{
		return false;
	}

	return true;
}

int main()
{
	if (!firstTestSorting() || !secondTestSorting() || !firstTestSearching() || !secondTestSearching() || !testOfBothFunctions())
	{
		printf("There are some mistakes in the programm :c");
		return -1;
	}

	int sizeOfTheArray = 0;
	int numberOfIntegers = 0;
	printf("Enter the size of the array: ");
	scanf_s("%d", &sizeOfTheArray);
	while (sizeOfTheArray <= 0)
	{
		printf("The size of the array has to be positive\n");
		printf("Enter the size of the array: ");
		scanf_s("%d", &sizeOfTheArray);
	}

	printf("Enter the number of integers: ");
	scanf_s("%d", &numberOfIntegers);
	while (numberOfIntegers <= 0)
	{
		printf("The number of integers has to be positive\n");
		printf("Enter the number of integers: ");
		scanf_s("%d", &numberOfIntegers);
	}

	int* firstArray = (int*)calloc(sizeOfTheArray, sizeof(int));
	if (firstArray == NULL)
	{
		printf("\nmemory is not found :c");
		return -1;
	}

	int* arrayOfIntegers = (int*)calloc(numberOfIntegers, sizeof(int));
	if (arrayOfIntegers == NULL)
	{
		free(firstArray);
		printf("\nmemory is not found :c");
		return -1;
	}

	randomFilling(firstArray, sizeOfTheArray);
	randomFilling(arrayOfIntegers, numberOfIntegers);
	printf("Your array is: ");
	for (int i = 0; i < sizeOfTheArray; i++)
	{
		printf("%d ", firstArray[i]);
	}

	printf("\nYour numbers are: ");
	for (int i = 0; i < numberOfIntegers; i++)
	{
		printf("%d ", arrayOfIntegers[i]);
	}

	qSort(firstArray, sizeOfTheArray, 0, sizeOfTheArray - 1);
	for (int i = 0; i < numberOfIntegers; i++)
	{
		if (binarySearch(firstArray, 0, sizeOfTheArray - 1, arrayOfIntegers[i]))
		{
			printf("\n%d is in array", arrayOfIntegers[i]);
		} else {
			printf("\n%d isn't in array", arrayOfIntegers[i]);
		}
	}

	free(arrayOfIntegers);
	free(firstArray);
	return 0;
}