#include <stdio.h>
#include <math.h>

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

	if (power == 0)
	{
		answer = 1;
	} else if (choise == 0) {
		answer = simplePower(number, power);
	} else {
		answer = fastPower(number, power);
	}

	printf("%lf", answer);

	return 0;
}