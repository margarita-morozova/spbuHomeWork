#include <stdio.h>
#include <stdbool.h>

unsigned long long int recursiveMethod(int currentNumber,int neededNumber, unsigned long long int theFirst, unsigned long long int theSecond)
{
	unsigned long long int nextFibonacciNumber = theFirst + theSecond;
	if (currentNumber + 1 < neededNumber)
	{
		recursiveMethod(currentNumber + 1, neededNumber, theSecond, nextFibonacciNumber);
	} else {
		return nextFibonacciNumber;
	}
}

unsigned long long int iterativeMethod(int currentNumber, int neededNumber, unsigned long long int theFirst, unsigned long long int theSecond)
{
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
	int number = 50;
	unsigned long long int rightAnswer = 12586269025;
	return (recursiveMethod(2, number, 1, 1) == iterativeMethod(2, number, 1, 1)) && (iterativeMethod(2, number, 1, 1) == rightAnswer);
}

bool theSecondTest()
{
	int number = 83;
	unsigned long long int rightAnswer = 99194853094755497;
	return (recursiveMethod(2, number, 1, 1) == iterativeMethod(2, number, 1, 1)) && (iterativeMethod(2, number, 1, 1) == rightAnswer);
}

bool IncorrectDataTest()
{
	int number = -5;
	return ()
}

int main()
{
	unsigned long long int theFirstNumber = 1;
	unsigned long long int theSecondNumber = 1;
	int decision = 0;
	int neededNumber = 0;
	int currentNumber = 2;

	printf("Enter the number of the needed Fibonacci number: ");
	scanf_s("%d", &neededNumber);

	printf("\nWhat method do you want to use?\nFor recusion press 0\nFor iterative method press 1\n");
	scanf_s("%d", &decision);
	while (decision != 1 && decision != 0)
	{
		printf("Try again\nWhat method do you want to use?\nFor recusion press 0\nFor iterative method press 1\n");
		scanf_s("%d", &decision);
	}

	unsigned long long int answer = 0;

	if (decision == 0)
	{
		answer = recursiveMethod(currentNumber, neededNumber, theFirstNumber, theSecondNumber);
	} else {
		answer = iterativeMethod(currentNumber, neededNumber, theFirstNumber, theSecondNumber);
	}

	printf("The answer is %llu", answer);

	return 0;
}