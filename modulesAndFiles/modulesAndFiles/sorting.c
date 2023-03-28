#include <stdio.h>

void qSortImplementation(int* originalArray, int beginning, int ending) {
	int supportElement = beginning;
	for (int i = beginning + 1; i < ending + 1; i++) {
		if (originalArray[supportElement] > originalArray[i]) {
			int temporaryPlace = originalArray[i];
			for (int j = i; j >= supportElement; j--) {
				originalArray[j] = originalArray[j - 1];
			}

			originalArray[supportElement] = temporaryPlace;
			++supportElement;
		}
	}

	if (supportElement - beginning > 0) {
		qSortImplementation(originalArray, beginning, supportElement - 1);
	}

	if (ending - supportElement > 0) {
		qSortImplementation(originalArray, supportElement + 1, ending);
	}
}

void qSort(int* originalArray, int size) {
	qSortImplementation(originalArray, 0, size - 1);
}