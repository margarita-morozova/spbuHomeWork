#include <stdio.h>
#include <stdlib.h>


int main() {
    int firstNumber = 0;
    int secondNumber = 0;
    int answerSign = 1;
    printf("Enter the first number: ");
    scanf_s("%d", &firstNumber);
    printf("\nEnter the second number: ");
    scanf_s("%d", &secondNumber);
    int absQuotient = 0;
    while (secondNumber == 0) {
        printf("You can't divide by zero :c\nTry again\n");
        printf("Enter the second number : ");
        scanf_s("%d", &secondNumber);
    }

    if (abs(firstNumber) < abs(secondNumber)) {
        printf("The answer is: %d", absQuotient);
        return 0;
    }
    else if ((firstNumber < 0 || secondNumber < 0) && !(firstNumber < 0 && secondNumber < 0)) {
        // make the firstNumber and the secondNumber of the same sign
        answerSign = -1;
        secondNumber *= -1;
    }

    while ((firstNumber - secondNumber * absQuotient < 0) || (firstNumber - secondNumber * absQuotient >= abs(secondNumber))) {
        ++absQuotient;
    }

    printf("The answer is: %d", absQuotient * answerSign);
    return 0;
}