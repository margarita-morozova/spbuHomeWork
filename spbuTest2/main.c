#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

void selectionSort(int originalArray[], int arraySize, int beginning, int ending)
{
	int indexOfMinimum = beginning;
	for (int i = beginning + 2; i <= ending; i += 2)
	{
		if (originalArray[i] < originalArray[indexOfMinimum])
		{
			indexOfMinimum = i;
		}
	}

	int temporaryPlace = originalArray[indexOfMinimum];
	originalArray[indexOfMinimum] = originalArray[beginning];
	originalArray[beginning] = temporaryPlace;

	if (arraySize - 4 >= 1)
	{
		selectionSort(originalArray, arraySize - 2, beginning + 2, ending);

	}
}

bool theFirstTest()
{
	int testArray[5] = {5, 4, 3, 2, 1};
	int arraySize = 5;
	int sortedArray[5] = {1, 4, 3, 2, 5};
	bool isProgrammCorrect = 1;

	selectionSort(testArray, arraySize, 0, arraySize - 1);

	for (int i = 0; i < arraySize; i++)
	{
		isProgrammCorrect = (testArray[i] == sortedArray[i]);
		if (!isProgrammCorrect)
		{
			break;
		}
	}
	return isProgrammCorrect;
}

bool theSecondTest()
{
	int testArray[13] = {-100, 4, 7, 0, 0, 3, 5, 29, 28, 27, 1, 8, -7};
	int arraySize = 13;
	int sortedArray[13] = {-100, 4, -7, 0, 0, 3, 1, 29, 5, 27, 7, 8, 28};
	bool isProgrammCorrect = 1;

	selectionSort(testArray, arraySize, 0, arraySize - 1);

	for (int i = 0; i < arraySize; i++)
	{
		isProgrammCorrect = (testArray[i] == sortedArray[i]);
		if (!isProgrammCorrect)
		{
			break;
		}
	}
	return isProgrammCorrect;
}

int main()
{
	int* originalArray;
	int arraySize = 0;
	printf("Enter the size of the array: ");
	scanf_s("%d", &arraySize);
	int beginning = 0;
	int ending = arraySize - 1;
	originalArray = (int*)malloc(arraySize * sizeof(int));

	if (originalArray == NULL)
	{
		printf(":(");
		return -1;
	}

	printf("Fill the array: ");
	for (int i = 0; i < arraySize; i++)
	{
		scanf_s("%d", &originalArray[i]);
	}

	selectionSort(originalArray, arraySize, 0, arraySize - 1);

	if (theFirstTest() && theSecondTest())
	{
		for (int i = 0; i < arraySize; i++)
		{
			printf("%d ", originalArray[i]);
		}
	} else {
		printf("The process failed :c");
		return -1;
	}

	free(originalArray);

	return 0;
}