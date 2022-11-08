#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define firstTestSize 10
#define secondTestSize 5

int* bubble(int* pointerToArray, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (pointerToArray[j] > pointerToArray[j + 1])
			{
				int temporaryPlace = pointerToArray[j];
				pointerToArray[j] = pointerToArray[j + 1];
				pointerToArray[j + 1] = temporaryPlace;
			}
		}
	}

	return pointerToArray;
}

int* counting(int* pointerToArray, int size)
{
	int extreme = 10000;
	int* arrayOfNumbers = calloc(extreme, sizeof(int));

	for (int i = 0; i < size; i++)
	{
		arrayOfNumbers[pointerToArray[i]]++;
	}

	int index = 0;
	while (index <= size)
	{
		for (int i = 0; i < extreme; i++)
		{
			while (arrayOfNumbers[i] > 0)
			{
				pointerToArray[index] = i;
				arrayOfNumbers[i]--;
				index++;
			}
		}
		index++;
	}
	free(arrayOfNumbers);

	return pointerToArray;
}

int* manualFilling(int *pointerToArray, int size)
{
	printf("Enter the positive elements of your array:\n");
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &pointerToArray[i]);
	}

	return pointerToArray;
}

int* randomFilling(int *pointerToArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		pointerToArray[i] = rand() % 10000;
	}

	return pointerToArray;
}

double countingTime()
{
	int size = 100000;
	int* firstArray = (int*)calloc(size, sizeof(int));
	randomFilling(firstArray, size);
	clock_t beginning = clock();
	counting(firstArray, size);
	clock_t ending = clock();

	return (double)(ending - beginning) / CLOCKS_PER_SEC;
}

double bubbleTime()
{
	int size = 100000;
	int* firstArray = (int*)calloc(size, sizeof(int));
	randomFilling(firstArray, size);
	clock_t beginning = clock();
	bubble(firstArray, size);
	clock_t ending = clock();

	return (double)(ending - beginning) / CLOCKS_PER_SEC;
}

bool firstTest()
{
	int firstTestArray[firstTestSize] = { 0, 50, 1043, 49, 2, 0, 1, 1, 50, 33 };
	int secondTestArray[firstTestSize] = { 50, 2, 1043, 49, 50, 1, 1, 0, 0, 33 };
	int sortedArray[firstTestSize] = { 0, 0, 1, 1, 2, 33, 49, 50, 50, 1043 };
	bubble(firstTestArray, firstTestSize);
	counting(secondTestArray, firstTestSize);

	for (int i = 0; i < firstTestSize; i++)
	{
		if (firstTestArray[i] != secondTestArray[i] || firstTestArray[i] != sortedArray[i])
		{
			return false;
		}
	}

	return true;
}

bool secondTest()
{
	int firstTestArray[secondTestSize] = { 1000, 5, 5, 1, 1};
	int secondTestArray[secondTestSize] = { 1, 5, 1, 5, 1000};
	int sortedArray[secondTestSize] = { 1, 1, 5, 5, 1000 };
	bubble(firstTestArray, secondTestSize);
	counting(secondTestArray, secondTestSize);

	for (int i = 0; i < secondTestSize; i++)
	{
		if (firstTestArray[i] != secondTestArray[i] || firstTestArray[i] != sortedArray[i])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	if (!firstTest() || !secondTest())
	{
		printf("Tests failed :c");
		return -1;
	}

	printf("Please, wait for the calculation to complete.\n");
	int size = 0;
	int firstDecision = 0;
	int secondDecision = 0;
	printf("Time that takes to sort the array of 100000 elements using bubble sort: %f\n", bubbleTime());
	printf("Time that takes to sort the array of 100000 elements using counting sort: %f\n", countingTime());
	printf("Enter the size of your array: ");
	scanf_s("%d", &size);
	printf("\nDo you want to enter the whole array or fill it randomly?\nFor manual filling press 0\nFor automatically filling press 1\n");
	scanf_s("%d", &firstDecision);

	while (firstDecision != 0 && firstDecision != 1)
	{
		printf("Try again\nDo you want to enter the whole array or fill it randomly?\nFor manual filling press 0\nFor automatically filling press 1\n");
		scanf_s("%d", &firstDecision);
	}

	int* firstArray = (int*)calloc(size, sizeof(int));
	if (firstArray == NULL)
	{
		printf("\nmemory is not found :c");
		return -1;
	}

	if (firstDecision == 0)
	{
		manualFilling(firstArray, size);
	} else {
		randomFilling(firstArray, size);
	}

	printf("If you want to use bubble sort, press 0\nIf you want to use counting sort press 1\n");
	scanf_s("%d", &secondDecision);
	while (secondDecision != 0 && secondDecision != 1)
	{
		printf("Try again\nIf you want to use bubble sort, press 0\nIf you want to use counting sort press 1\n");
		scanf_s("%d", &secondDecision);
	}

	if (secondDecision == 0)
	{
		bubble(firstArray, size);
	} else {
		counting(firstArray, size);
	}

	printf("\nSorted array: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", firstArray[i]);
	}

	free(firstArray);
	return 0;
}