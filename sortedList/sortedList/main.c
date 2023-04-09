#include "list.h"

#include <stdio.h>
#include <stdbool.h>

void instruction() {
	printf("\nEnter:\n"
		"0 to exit\n"
		"1 to add new value to the list\n"
		"2 to delete value from the list\n"
		"3 to print the list\n");
}

bool test() {
	struct SortedList* list = createList();
	if (push(list, 5)) {
		return false;
	}

	if (push(list, 2)) {
		return false;
	}

	if (!isSorted(list)) {
		return false;
	}

	if (!deleteValue(list, 1)) {
		return false;
	}

	if (deleteValue(list, 5)) {
		return false;
	}

	deleteList(list);
	return true;
}

int main() {
	if (!test()) {
		printf("There are some problems in the programm :c");
		return -1;
	}

	int command = -1;
	instruction();
	scanf_s("%d", &command);
	struct SortedList* list = createList();
	while (command != 0) {
		while (command < 0 || command > 3) {
			printf("\nThere are no such command\n");
			instruction();
			scanf_s("%d", &command);
		}
		if (command == 0) {
			deleteList(list);
		}
		else if (command == 1) {
			int newValue = 0;
			printf("\nEnter value: ");
			scanf_s("%d", &newValue);
			int errorCode = push(list, newValue);
			if (errorCode == -1) {
				printf("\nThere is no list\n");
				return -1;
			}
			else if (errorCode == -2) {
				printf("\nThere are some problems with memory allocation\n");
				deleteList(list);
				return -1;
			}
		}
		else if (command == 2) {
			int newValue = 0;
			printf("\nEnter value: ");
			scanf_s("%d", &newValue);
			int errorCode = deleteValue(list, newValue);
			if (errorCode == -1) {
				printf("\nThere is no list\n");
				return -1;
			}
			else if (errorCode == -3) {
				printf("\nThere is no such value in the list\n");
			}
		}
		else {
			int errorCode = printList(list);
			if (errorCode == -1) {
				printf("\nThere is no list\n");
			}
		}

		printf("\nEnter next command: ");
		scanf_s("%d", &command);
	}

	deleteList(list);
	return 0;
}