#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

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
	int middle = beginning + (ending - beginning) / 2;
	if (beginning < ending) {
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

int main()
{
	int sizeOfTheArray = 0;
	int numberOfIntegers = 0;
	printf("Enter the size of the array: ");
	scanf_s("%d", &sizeOfTheArray);
	printf("Enter the number of integers: ");
	scanf_s("%d", &numberOfIntegers);

	int* firstArray = (int*)calloc(sizeOfTheArray, sizeof(int));
	if (firstArray == NULL)
	{
		printf("\nmemory is not found :c");
		return -1;
	}

	int* arrayOfIntegers = (int*)calloc(numberOfIntegers, sizeof(int));
	if (arrayOfIntegers == NULL)
	{
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

	return 0;
}