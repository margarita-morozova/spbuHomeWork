#include <stdio.h>

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