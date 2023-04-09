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
		current->nextElement = calloc(1, sizeof(Node));
		if (current->nextElement == NULL) {
			return -2;
		}

		current->nextElement->nextElement = list->head;
		current->nextElement->value = value;
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
	while (current->value != value) {
		previous = current;
		current = current->nextElement;
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

void deleteList(List* list) {
	free(list->head);
	free(list);
}

int printList(List* list) {
	if (list == NULL) {
		return -1;
	}

	Node* current = list->head;
	printf("Needed position is: ");
	while (current != NULL) {
		printf("%d ", current->value);
		current = current->nextElement;
	}

	return 0;
}