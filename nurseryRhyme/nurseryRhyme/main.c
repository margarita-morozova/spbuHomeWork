#include "cyclicList.h"

#include <stdio.h>
#include <stdbool.h>

int rhyme(int numberOfWarriors, int positionOfTheKilledWarrior, struct List* list) {
	for (int i = 1; i <= numberOfWarriors; i++) {
		if (push(list, i)) {
			return -1;
		}
	}
	
	int errorCode = -5;
	int shiftValue = positionOfTheKilledWarrior - 1;
	while (errorCode != 1) {
		errorCode = deleteValue(list, shiftValue);
		if (errorCode == -1) {
			return -1;
		}
	}

	return 0;
}

bool test(int numberOfWarriors, int positionOfTheKilledWarrior, int answer) {
	struct List* list = createList();
	rhyme(numberOfWarriors, positionOfTheKilledWarrior, list);
	return isRightAnswer(answer, list);
}

int main() {
	if (!test(5, 2, 3) || !test(7, 4, 2) || !test(14, 2, 13) || !test(1, 10, 1)) {
		printf("There are some problems in the program :c");
		return -1;
	}

	int numberOfWarriors = 0;
	int positionOfTheKilledWarrior = 0;
	printf("Enter the number of the warriors: ");
	scanf_s("%d", &numberOfWarriors);
	while (numberOfWarriors < 1) {
		printf("\nThe number of warriors has to be positive.\n");
		printf("Enter the number of the warriors: ");
		scanf_s("%d", &numberOfWarriors);
	}

	printf("\nEnter the position of each killed warrior: ");
	scanf_s("%d", &positionOfTheKilledWarrior);
	while (positionOfTheKilledWarrior < 1) {
		printf("\nThe number of each killed warrior has to be positive.\n");
		printf("Enter the number of each killed warrior: ");
		scanf_s("%d", &positionOfTheKilledWarrior);
	}

	struct List* list = createList();
	if (rhyme(numberOfWarriors, positionOfTheKilledWarrior, list)) {
		printf("Problems with memory allocation :c");
		return -1;
	}

	printList(list);
	deleteList(list);
	return 0;
}