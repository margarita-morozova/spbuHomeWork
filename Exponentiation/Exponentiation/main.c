#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double simplePower(double number, int power) {
	double answer = 1;
	int temporaryPower = abs(power);
	for (int i = 0; i < temporaryPower; i++) {
		answer *= number;
	}

	return power >= 0 ? answer : 1 / answer;
}

double fastPower(double number, int power) {
	double answer = 1;
	int temporaryPower = abs(power);
	double temporaryNumber = number;
	while (temporaryPower > 0) {
		if (temporaryPower % 2 == 0) {
			temporaryPower /= 2;
			temporaryNumber *= temporaryNumber;
		} else {
			temporaryPower--;
			answer *= temporaryNumber;
		}
	}

	return power >= 0 ? answer : 1 / answer;
}

bool test(double number, int power, double rightAnswer, double delta) {
	return (abs(simplePower(number, power) - fastPower(number, power)) < delta) && (abs(fastPower(number, power) - rightAnswer) < delta);
}

int main() {
	if (!(test(10, 2, 100, 0.00001) && test(10, -2, 0.01, 0.00001) && test(1000, 0, 1, 0.00001))) {
		printf("Tests failed :c");
		return -1;
	}

	double number = 0;
	int power = 0;
	int choise = 0;
	double answer = 0;
	printf("Enter the number: ");
	scanf_s("%lf", &number);
	printf("\nEnter the power: ");
	scanf_s("%d", &power);
	printf("Choose the way you want to raise your number to a power:\nFor simle way enter 0\nFor quick way enter 1\n");
	scanf_s("%d", &choise);

	if (choise == 0) {
		answer = simplePower(number, power);
	} else {
		answer = fastPower(number, power);
	}

	printf("The answer is %lf", answer);

	return 0;
}