#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* - 1 - list is empty
-2 - error in memory allocation
-3 - there is no needed value*/

typedef struct Node {
	int value;
	struct Node* nextElement;
} Node;

typedef struct SortedList {
	Node* head;
} SortedList;

SortedList* createList() {
	return calloc(1, sizeof(SortedList));
}

int push(SortedList* sortedList, int value) {
	if (sortedList == NULL) {
		return -1;
	}

	Node* current = sortedList->head;
	Node* previous = calloc(1, sizeof(SortedList));
	if (previous == NULL) {
		return -1;
	}

	if (current == NULL) {
		sortedList->head = calloc(1, sizeof(Node));
		if (sortedList->head == NULL) {
			return -1;
		}

		sortedList->head->value = value;
		return 0;
	}

	while (current->nextElement != NULL && current->value < value) {
		previous = current;
		current = current->nextElement;
		free(previous);
	}

	if (current->nextElement == NULL && current->value < value) {
		current->nextElement = calloc(1, sizeof(Node));
		if (current->nextElement == NULL) {
			return -2;
		}

		current->nextElement->nextElement = NULL;
		current->nextElement->value = value;
		return 0;
	}

	if (current == sortedList->head) {
		Node* newPlace = calloc(1, sizeof(Node));
		if (newPlace == NULL) {
			return -2;
		}

		newPlace->nextElement = current;
		newPlace->value = value;
		sortedList->head = newPlace;
		free(previous);
		return 0;
	}

	Node* newPlace = calloc(1, sizeof(Node));
	if (newPlace == NULL) {
		return -2;
	}

	newPlace->value = value;
	newPlace->nextElement = previous->nextElement;
	previous->nextElement = newPlace;
	return 0;
}

int deleteValue(SortedList* list, int value) {
	if (list == NULL) {
		return -1;
	}

	Node* current = list->head;
	Node* previous = calloc(1, sizeof(Node));
	while (current->nextElement != NULL && current->value != value) {
		previous = current;
		current = current->nextElement;
	}

	if (current->nextElement == NULL && current->value != value) {
		return -3;
	}

	if (current == list->head) {
		list->head = current->nextElement;
	}
	else {
		previous->nextElement = current->nextElement;
	}

	free(current);
	return 0;
}

void deleteList(SortedList* list) {
	if (list == NULL) {
		return;
	}

	Node* current = list->head;
	while (current != NULL) {
		Node* placeToDelete = current;
		current = current->nextElement;
		free(placeToDelete);
	}

	free(list);
}

int printList(SortedList* list) {
	if (list == NULL) {
		return -1;
	}

	Node* current = list->head;
	printf("Your list is: ");
	while (current != NULL) {
		printf("%d ", current->value);
		current = current->nextElement;
	}

	return 0;
}

bool isSorted(SortedList* list) {
	if (list == NULL) {
		return true;
	}

	Node* current = list->head;
	while (current->nextElement != NULL) {
		if (current->value > current->nextElement->value) {
			return false;
		}

		current = current->nextElement;
	}

	return true;
}