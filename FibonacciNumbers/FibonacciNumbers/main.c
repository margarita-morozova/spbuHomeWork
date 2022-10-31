#include <stdio.h>
#include <stdbool.h>

unsigned long long int recursiveMethod(int neededNumber)
{
	if (neededNumber <= 0)
	{
		return -1;
	}

	if (neededNumber <= 2)
	{
		return 1;
	} else {
		return recursiveMethod(neededNumber - 1) + recursiveMethod(neededNumber - 2);
	}
}

unsigned long long int iterativeMethod(int currentNumber, int neededNumber, unsigned long long int theFirst, unsigned long long int theSecond)
{
	if (neededNumber <= 0)
	{
		return -1;
	}

	unsigned long long int theFirstNumber = theFirst;
	unsigned long long int theSecondNumber = theSecond;
	unsigned long long int theCurrentNumber = currentNumber;
	unsigned long long int theNeededNumber = neededNumber;

	while (theCurrentNumber < theNeededNumber)
	{
		theSecondNumber += theFirstNumber;
		theFirstNumber = theSecondNumber - theFirstNumber;
		++theCurrentNumber;
	}

	return theSecondNumber;
}

bool theFirstTest()
{
	int number = 1;
	unsigned long long int rightAnswer = 1;
	return (recursiveMethod(number) == iterativeMethod(2, number, 1, 1)) && (iterativeMethod(2, number, 1, 1) == rightAnswer);
}

bool theSecondTest()
{
	int number = 10;
	unsigned long long int rightAnswer = 55;
	return (recursiveMethod(number) == iterativeMethod(2, number, 1, 1)) && (iterativeMethod(2, number, 1, 1) == rightAnswer);
}

bool IncorrectDataTest()
{
	int number = -5;
	return (recursiveMethod(number) == iterativeMethod(2, number, 1, 1)) && (iterativeMethod(2, number, 1, 1) == -1);
}

int main()
{
	unsigned long long int theFirstNumber = 1;
	unsigned long long int theSecondNumber = 1;
	int decision = 0;
	int neededNumber = 0;
	int currentNumber = 2;

	if (!(theFirstTest() == theSecondTest() && theFirstTest() == IncorrectDataTest() && IncorrectDataTest() == 1))
	{
		printf("%d %d %d", theFirstTest(), theSecondTest(), IncorrectDataTest());
		printf("Tests failed :c");
		return -1;
	}

	printf("Enter the number of the needed Fibonacci number: ");
	scanf_s("%d", &neededNumber);

	printf("\nWhat method do you want to use?\nFor recursion press 0\nFor iterative method press 1\n(use the recursion if the number of the needed Fibonacci number is less than 37)\n");
	scanf_s("%d", &decision);
	while (decision != 1 && decision != 0)
	{
		printf("Try again\nWhat method do you want to use?\nFor recursion press 0\nFor iterative method press 1\n(use the recursion if the number of the needed Fibonacci number is less than 37)\n");
		scanf_s("%d", &decision);
	}

	unsigned long long int answer = 0;

	if (decision == 0)
	{
		answer = recursiveMethod(neededNumber);
	} else {
		answer = iterativeMethod(currentNumber, neededNumber, theFirstNumber, theSecondNumber);
	}

	if (answer == -1)
	{
		printf("You can't work with negative numbers");
	}

	printf("Your Fibonacci number is %llu", answer);

	return 0;
}