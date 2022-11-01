#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double simplePower(double number, int power)
{
	double answer = 1;
	int temporaryPower = abs(power);
	for (int i = 0; i < temporaryPower; i++)
	{
		answer *= number;
	}

	if (power > 0)
	{
		return answer;
	}

	return 1 / answer;
}

double fastPower(double number, int power)
{
	double answer = 1;
	int temporaryPower = abs(power);
	double temporaryNumber = number;
	while (temporaryPower > 0)
	{
		if (temporaryPower % 2 == 0)
		{
			temporaryPower /= 2;
			temporaryNumber *= temporaryNumber;
		} else {
			temporaryPower--;
			answer *= temporaryNumber;
		}
	}

	if (power > 0)
	{
		return answer;
	} else {
		return 1 / answer;
	}
}

bool theFirstTest()
{
	double number = 10;
	int power = 2;
	double rightAnswer = 100;
	double delta = 0.00001;

	return (abs(simplePower(number, power) - fastPower(number, power)) < delta) && (abs(fastPower(number, power) - rightAnswer) < delta);
}

bool theSecondTest()
{
	double number = 10;
	int power = -2;
	double rightAnswer = 0.01;
	double delta = 0.00001;

	return (abs(simplePower(number, power) - fastPower(number, power)) < delta) && (abs(fastPower(number, power) - rightAnswer) < delta);
}

bool theThirdTest()
{
	double number = 1000;
	int power = 0;
	double rightAnswer = 1;
	double delta = 0.00001;

	return (abs(simplePower(number, power) - fastPower(number, power)) < delta) && (abs(fastPower(number, power) - rightAnswer) < delta);
}

int main()
{
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

	if (!(theFirstTest() && theSecondTest() && theThirdTest()))
	{
		printf("Tests failed :c");
		return -1;
	}

	if (power == 0)
	{
		answer = 1;
	} else if (choise == 0) {
		answer = simplePower(number, power);
	} else {
		answer = fastPower(number, power);
	}

	printf("The answer is %lf", answer);

	return 0;
}