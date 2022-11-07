#include <stdio.h>
#include <stdlib.h>

int bubble(int* pointerToArray, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i - 1; j < size - 1; j++)
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

int counting()
{

}

int manualFilling(int *pointerToArray, int size)
{
	printf("Enter the elements fo your array:\n");
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &pointerToArray[i]);
	}

	return pointerToArray;
}

int randomFilling(int *pointerToArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		pointerToArray[i] = rand();
	}

	return pointerToArray;
}

int main()
{
	int size = 0;
	int decision = 0;
	printf("Enter the size of the array: ");
	scanf_s("%d", &size);
	printf("\nDo you want to enter the whole array or fill it randomly?\nFor manual filling press 0\nFor automatically filling press 1\n");
	scanf_s("%d", &decision);

	while (decision != 0 && decision != 1)
	{
		printf("Try again\nDo you want to enter the whole array or fill it randomly?\nFor manual filling press 0\nFor automatically filling press 1\n");
		scanf_s("%d", &decision);
	}

	int* firstArray = (int*)calloc(size, sizeof(int));
	if (decision == 0)
	{
		manualFilling(firstArray, size);
	} else {
		randomFilling(firstArray, size);
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d ", firstArray[i]);
	}

	bubble(firstArray, size);
	printf("\nSorted array: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", firstArray[i]);
	}


	free(firstArray);

	return 0;
}