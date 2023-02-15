#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
        int primeNumber = 1;
        for (int devider = 2; devider <= round(pow(i, 0.5)); ++devider) {
            if (i % devider == 0) {
                primeNumber = 0;
            }
        }

        if (primeNumber) {
            printf("%d ", i);
        }
    }

    return 0;
}