#include <stdio.h>

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

int main()
{
	int mas[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	qsort(mas, 10, 0, 9);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", mas[i]);
	}

	return 0;
}