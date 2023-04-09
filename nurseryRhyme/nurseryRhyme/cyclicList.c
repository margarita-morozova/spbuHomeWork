#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
	int value;
	struct Node* nextElement;
} Node;

typedef struct List {
	Node* head;
} List;

List* createList() {
	return calloc(1, sizeof(List));
}

int push(List* list, int value) {
	if (list == NULL) {
		return -1;
	}

	Node* current = list->head;
	if (current == NULL) {
		list->head = calloc(1, sizeof(Node));
		if (list->head == NULL) {
			return -1;
		}

		list->head->nextElement = list->head;
		list->head->value = value;
		return 0;
	}

	while (current->nextElement != list->head) {
		current = current->nextElement;
	}

	if (current->nextElement == list->head) {
		Node* newPlace = calloc(1, sizeof(Node));
		if (newPlace == NULL) {
			return -1;
		}

		newPlace->nextElement = list->head;
		newPlace->value = value;
		current->nextElement = newPlace;
		return 0;
	}

	return 0;
}

int deleteValue(List* list, int value) {
	if (list == NULL) {
		return -1;
	}

	Node* current = list->head;
	Node* previous = calloc(1, sizeof(Node));
	if (current->value == current->nextElement->value) {
		return 1;
	}

	for (int i = 0; i < value; i++) {
		previous = current;
		current = current->nextElement;
	}

	list->head = current->nextElement;
	previous->nextElement = current->nextElement;
	free(current);
	return 0;
}

void deleteList(List* list) {
	free(list->head);
	free(list);
}

int printList(List* list) {
	if (list == NULL) {
		return -1;
	}

	Node* current = list->head;
	printf("Needed position is: %d", current->value);
	return 0;
}

bool isRightAnswer(int rightAnswer, List* list) {
	int answer = list->head->value;
	deleteList(list);
	return rightAnswer == answer;
}