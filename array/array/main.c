#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseTheArray(int* theWholeArray, int beginning, int ending) {
    for (int i = beginning; i < beginning + (ending - beginning + 1) / 2; i++) {
        int temporaryPlace = theWholeArray[i];
        theWholeArray[i] = theWholeArray[ending - i + beginning];
        theWholeArray[ending - i + beginning] = temporaryPlace;
    }
}

int main() {
    int sizeOfTheFirstPart = 0;
    int sizeOfTheSecondPart = 0;
    printf("Enter the size of the first part of the array: ");
    scanf_s("%d", &sizeOfTheFirstPart);
    printf("\nEnter the size of the second part of the array: ");
    scanf_s("%d", &sizeOfTheSecondPart);

    int *theWholeArray = (int*)malloc((sizeOfTheFirstPart + sizeOfTheSecondPart) * sizeof(int));
    printf("Enter each element of the array from a new line:\n");
    for (int i = 0; i < sizeOfTheFirstPart + sizeOfTheSecondPart; i++) {
        scanf_s("%d", &theWholeArray[i]);
    }

    reverseTheArray(theWholeArray, 0, sizeOfTheFirstPart - 1);
    reverseTheArray(theWholeArray, sizeOfTheFirstPart, sizeOfTheFirstPart + sizeOfTheSecondPart - 1);
    reverseTheArray(theWholeArray, 0, sizeOfTheFirstPart + sizeOfTheSecondPart - 1);

    printf("The result is: ");
    for (int i = 0; i < sizeOfTheFirstPart + sizeOfTheSecondPart; i++) {
        printf("%d ", theWholeArray[i]);
    }

    free(theWholeArray);

    return 0;
}
