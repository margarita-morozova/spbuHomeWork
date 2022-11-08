#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* halfQSort(int* pointerToArray, int size)
{
	int index = 0;
	int supportElement = pointerToArray[0];
	for (int i = 0; i < size; i++)
	{
		if (pointerToArray[i] < supportElement)
		{
			int temporaryPlace = pointerToArray[i];
			for (int j = i; j > index; j--)
			{
				pointerToArray[j] = pointerToArray[j - 1];
			}
			pointerToArray[index] = temporaryPlace;
			index++;
		}
	}

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

	return 0;
}