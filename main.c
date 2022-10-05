#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>


int insertionSort(int originalArray[], int arraySize, int beginning, int ending)
{
	
	for (int i = beginning; i <= ending; i++)
	{
		for (int j = i; j >= beginning; j--)
		{
			if (originalArray[j] < originalArray[j - 1])
			{
				int temporaryPlace = 0;
				temporaryPlace = originalArray[j];
				originalArray[j] = originalArray[j - 1];
				originalArray[j - 1] = temporaryPlace;
			}
		}
	}
	
}

void qsort(int originalArray[], int size, int beginning, int ending)
{
	int supportElement = beginning;
	for (int i = 1; i < size; i++)
	{
		if (originalArray[supportElement] >= originalArray[i])
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
	
	if (supportElement - beginning >= 10)
	{
		qsort(originalArray, supportElement - beginning, beginning, supportElement - 1);
	} else {
		insertionSort(originalArray, supportElement - beginning, beginning, supportElement - 1);
	}

	if (ending - supportElement >= 10)
	{
		qsort(originalArray, ending - supportElement, supportElement + 1, ending);
	} else {
		insertionSort(originalArray, ending - supportElement, supportElement + 1, ending);
	}
}

void theFirstTest()
{
	int testArray[15] = { 6, 3, 5, 9, 3, 7, 4, 6, 8, 2, 5, 0, 10, -5, -8 };
	qsort(testArray, 15, 0, 14);

	for (int i = 0; i < 15; i++)
	{
		printf("%d ", testArray[i]);
	}
}

void theSecondTest()
{
	int testArray[10] = { 3, 6, -4, -5, 2, 100, 76, 2, 10, 6};
	qsort(testArray, 10, 0, 9);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", testArray[i]);
	}
}

void theThirdTest()
{
	int testArray[10] = { 1, 2, 1, 2, 1, 2, 1, 2, 1, 2 };
	qsort(testArray, 10, 0, 9);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", testArray[i]);
	}
}

void theFourthTest()
{
	int testArray[13] = { 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	qsort(testArray, 13, 0, 12);

	for (int i = 0; i < 13; i++)
	{
		printf("%d ", testArray[i]);
	}
}

void theFifthTest()
{
	int testArray[9] = { 13, 12, 11, 10, 9, 8, 7, 6, 5};
	qsort(testArray, 9, 0, 8);

	for (int i = 0; i < 9; i++)
	{
		printf("%d ", testArray[i]);
	}
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

	if (arraySize < 10)
	{
		insertionSort(originalArray, arraySize, beginning, ending);
	} else {
		qsort(originalArray, arraySize, beginning, ending);
	}

	for (int i = 0; i < arraySize; i++)
	{
		printf("%d ", originalArray[i]);
	}

	free(originalArray);

	return 0;
}