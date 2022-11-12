#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void qSort(int* originalArray, int size, int beginning, int ending)
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

int theMostFrequentElement(int *pointerToArray, int size)
{
	int neededElement = -100;
	int numberOfTheElement = 0;
	int count = 1;
	for (int i = 1; i < size; i++)
	{
		if (pointerToArray[i] == pointerToArray[i - 1])
		{
			++count;
		}
		else {
			if (count > numberOfTheElement)
			{
				numberOfTheElement = count;
				neededElement = pointerToArray[i - 1];
			}

			count = 1;
		}
	}

	return neededElement;
}

int* randomFilling(int* pointerToArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		pointerToArray[i] = rand() % 100;
	}

	return pointerToArray;
}

int main()
{
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
	printf("Your array: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", firstArray[i]);
	}

	qSort(firstArray, size, 0, size - 1);
	printf("\nThe most frequent element in your array is %d", theMostFrequentElement(firstArray, size));

	return 0;
}