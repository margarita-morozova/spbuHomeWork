#include <stdio.h>
#include <stdbool.h>

unsigned long long int recursiveMethod(int neededNumber){
	if (neededNumber <= 0){
		return -1;
	}

	if (neededNumber <= 2){
		return 1;
	} else {
		return recursiveMethod(neededNumber - 1) + recursiveMethod(neededNumber - 2);
	}
}

unsigned long long int iterativeMethod(int neededNumber){
	if (neededNumber <= 0){
		return -1;
	}

	unsigned long long int theFirstNumber = 1;
	unsigned long long int theSecondNumber = 1;
	unsigned long long int theCurrentNumber = 2;
	unsigned long long int theNeededNumber = neededNumber;

	while (theCurrentNumber < theNeededNumber){
		theSecondNumber += theFirstNumber;
		theFirstNumber = theSecondNumber - theFirstNumber;
		++theCurrentNumber;
	}

	return theSecondNumber;
}

bool test(int number, unsigned long long rightAnswer) {
	return (recursiveMethod(number) == iterativeMethod(number)) && (iterativeMethod(number) == rightAnswer);
}

int main(){
	unsigned long long int theFirstNumber = 1;
	unsigned long long int theSecondNumber = 1;
	int decision = 0;
	int neededNumber = 0;
	int currentNumber = 2;

	if (!test(1, 1) || !test(10, 55) || !test(-5, -1)) {
		printf("Tests failed :c");
		return -1;
	}

	printf("Enter the number of the needed Fibonacci number: ");
	scanf_s("%d", &neededNumber);

	printf("\nWhat method do you want to use?\nFor recursion press 0\nFor iterative method press 1\n(use the recursion if the number of the needed Fibonacci number is less than 37)\n");
	scanf_s("%d", &decision);
	while (decision != 1 && decision != 0){
		printf("Try again\nWhat method do you want to use?\nFor recursion press 0\nFor iterative method press 1\n(use the recursion if the number of the needed Fibonacci number is less than 37)\n");
		scanf_s("%d", &decision);
	}

	unsigned long long int answer = 0;

	if (decision == 0){
		answer = recursiveMethod(neededNumber);
	} else {
		answer = iterativeMethod(neededNumber);
	}

	if (answer == -1){
		printf("You can't work with negative numbers");
	}

	printf("Your Fibonacci number is %llu", answer);

	return 0;
}