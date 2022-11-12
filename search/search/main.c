#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void qsort(int *originalArray, int size, int beginning, int ending)
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

	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", originalArray[i]);
	}

	if (supportElement - beginning > 0)
	{
		qsort(originalArray, supportElement - beginning, beginning, supportElement - 1);
	}

	if (ending - supportElement > 0)
	{
		qsort(originalArray, ending - supportElement, supportElement + 1, ending);
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

int main()
{
	int mas[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	if (binarySearch(mas, 0, 9, 4))
	{
		printf("Yes\n");
	}

	if (!binarySearch(mas, 0, 9, 10))
	{
		printf("No\n");
	}

	return 0;
}