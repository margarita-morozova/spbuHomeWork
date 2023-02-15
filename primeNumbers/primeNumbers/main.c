#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    int number = 0;
    printf("Enter your number: ");
    scanf_s("%d", &number);

    if (number < 2) {
        printf("There are no prime numbers");
        return 0;
    }

    printf("Prime numbers are: ");
    for (int i = 2; i <= number; ++i) {
        bool isPrimeNumber = true;
        for (int divider = 2; divider * divider <= i; ++divider) {
            if (i % divider == 0) {
                isPrimeNumber = false;
            }
        }


        if (isPrimeNumber) {
            printf("%d ", i);
        }
    }

    return 0;
}