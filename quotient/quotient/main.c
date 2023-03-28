#include <stdio.h>
#include <stdlib.h>

int main() {
    int firstNumber = 0;
    int secondNumber = 0;
    printf("Enter the first number: ");
    scanf_s("%d", &firstNumber);
    printf("\nEnter the second number: ");
    scanf_s("%d", &secondNumber);
    int divider = 0;
    while (secondNumber == 0) {
        printf("You can't divide by zero :c\nTry again\n");
        printf("Enter the second number : ");
        scanf_s("%d", &secondNumber);
    }

    if (abs(firstNumber) < abs(secondNumber)) {
        printf("%d", divider);
        return 0;
    }
    else if (firstNumber * secondNumber >= 0 && firstNumber >= 0) {
        while (abs(firstNumber) >= abs(secondNumber)) {
            firstNumber -= secondNumber;
            ++divider;
        }
    }
    else if (firstNumber * secondNumber >= 0 && firstNumber < 0) {
        while (firstNumber < 0) {
            firstNumber -= secondNumber;
            ++divider;
        }
    }
    else if (firstNumber < secondNumber) {
        while ((firstNumber < 0) || (firstNumber >= abs(secondNumber))) {
            firstNumber += secondNumber;
            --divider;
        }
    }
    else {
        while (firstNumber + secondNumber >= 0) {
            firstNumber += secondNumber;
            --divider;
        }
    }

    printf("%d", divider);
    return 0;
}