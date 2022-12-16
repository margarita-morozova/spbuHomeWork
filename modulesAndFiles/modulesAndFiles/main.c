#include "sorting.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define firstTestArraySize 10
#define secondTestArraySize 9

int theMostFrequentElement(int* pointerToArray, int size)
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

bool firstTest()
{
	int testArray[firstTestArraySize] = { 5, 5, 3, 4, 2, 8, 8, 9, 8, 0 };
	int rightArray[firstTestArraySize] = { 0, 2, 3, 4, 5, 5, 8, 8, 8, 9 };
	int answer = 8;
	qSort(testArray, firstTestArraySize, 0, firstTestArraySize - 1);
	for (int i = 0; i < firstTestArraySize; i++)
	{
		if (testArray[i] != rightArray[i])
		{
			return false;
		}
	}

	return theMostFrequentElement(testArray, firstTestArraySize) == answer;
}

bool secondTest()
{
	int testArray[secondTestArraySize] = { 8, 8, 8, 5, 5, 5, 4, 0, 9 };
	int rightArray[secondTestArraySize] = { 0, 4, 5, 5, 5, 8, 8, 8, 9 };
	int answer = 5;
	qSort(testArray, secondTestArraySize, 0, secondTestArraySize - 1);
	for (int i = 0; i < secondTestArraySize; i++)
	{
		if (testArray[i] != rightArray[i])
		{
			return false;
		}
	}

	return theMostFrequentElement(testArray, secondTestArraySize) == answer;
}

int main()
{
	if (!firstTest() || !secondTest())
	{
		printf("There are some mistakes in the programm :c\n");
		return -1;
	}

	FILE* file;
	fopen_s(&file, "..\\testFile.txt", "r");
	if (file == NULL) {
		printf("file not found!");
		return 0;
	}

	fseek(file, 0, SEEK_SET);
	int size = 0;
	fscanf_s(file, "%d", &size);

	if (size < 1)
	{
		printf("\nThe wrong data in the file\n");
		return -1;
	}

	int* firstArray = (int*)calloc(size, sizeof(int));
	if (firstArray == NULL)
	{
		printf("\nmemory is not found :c");
		return -1;
	}

	for (int i = 0; i < size; i++) {
		fscanf_s(file, "%d", &firstArray[i]);
	}

	printf("Your array: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", firstArray[i]);
	}

	qSort(firstArray, size, 0, size - 1);
	printf("\nThe most frequent element in your array is %d", theMostFrequentElement(firstArray, size));

	return 0;
}