#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define firstTestSize 10
#define secondTestSize 5
#define thirdTestSize 2
#define fourthTestSize 4

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

bool firstTest()
{
	int testArray[firstTestSize] = { 10, 5, 7, 3, 9, 10, 45, 23, 7, 90 };
	int rightArray[firstTestSize] = { 5, 7, 3, 9, 7, 10, 10, 45, 23, 90 };
	bool isSortingRight = true;
	halfQSort(testArray, firstTestSize);
	for (int i = 0; i < firstTestSize; i++)
	{
		if (testArray[i] != rightArray[i])
		{
			isSortingRight = false;
		}
	}

	return isSortingRight;
}

bool secondTest()
{
	int testArray[secondTestSize] = { 1, 5, 3, 6, 7};
	int rightArray[secondTestSize] = { 1, 5, 3, 6, 7 };
	bool isSortingRight = true;
	halfQSort(testArray, secondTestSize);
	for (int i = 0; i < secondTestSize; i++)
	{
		if (testArray[i] != rightArray[i])
		{
			isSortingRight = false;
		}
	}

	return isSortingRight;
}

bool thirdTest()
{
	int testArray[thirdTestSize] = { 2, -5};
	int rightArray[thirdTestSize] = {-5, 2};
	bool isSortingRight = true;
	halfQSort(testArray, thirdTestSize);
	for (int i = 0; i < thirdTestSize; i++)
	{
		if (testArray[i] != rightArray[i])
		{
			isSortingRight = false;
		}
	}

	return isSortingRight;
}

bool fourthTest()
{
	int testArray[fourthTestSize] = { 1, 1, 1, 1};
	int rightArray[fourthTestSize] = { 1, 1, 1, 1};
	bool isSortingRight = true;
	halfQSort(testArray, fourthTestSize);
	for (int i = 0; i < fourthTestSize; i++)
	{
		if (testArray[i] != rightArray[i])
		{
			isSortingRight = false;
		}
	}

	return isSortingRight;
}

int main()
{
	if (!firstTest() || !secondTest() || !thirdTest() || !fourthTest())
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
	
	return 0;
}