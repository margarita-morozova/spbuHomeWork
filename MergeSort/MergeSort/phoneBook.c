#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct Node {
	char name[MAX_LENGTH];
	char phoneNumber[MAX_LENGTH];
	struct Node* nextElement;
} Node;

typedef struct phoneBook {
	Node* head;
} phoneBook;

phoneBook* createPhoneBook() {
	return calloc(1, sizeof(phoneBook));
}

int push(phoneBook* phoneBook, char name[], char phoneNumber[]) {
	if (phoneBook == NULL) {
		return -1;
	}

	Node* current = phoneBook->head;
	if (current == NULL) {
		phoneBook->head = calloc(1, sizeof(phoneBook));
		if (phoneBook->head == NULL) {
			return -1;
		}

		strcpy(phoneBook->head->name, name);
		strcpy(phoneBook->head->phoneNumber, phoneNumber);
	}

	while (current->nextElement != NULL) {
		current = current->nextElement;
	}

	current->nextElement = calloc(1, sizeof(1, phoneBook));
	if (current->nextElement == NULL) {
		return -2;
	}

	strcpy(current->nextElement->name, name);
	strcpy(current->nextElement->phoneNumber, phoneNumber);
	return 0;
}

void deleteBook(phoneBook* phoneBook) {
	if (phoneBook == NULL) {
		return;
	}

	Node* current = phoneBook->head;
	while (current != NULL) {
		Node* placeToDelete = current;
		current = current->nextElement;
		free(placeToDelete);
	}

	free(phoneBook);
}

int printToFile(phoneBook* phoneBook, const char* file) {
	FILE* newFile = fopen(file, "w");
	if (newFile == NULL) {
		fclose(newFile);
		return -2;
	}

	Node* current = phoneBook->head;
	if (current == NULL) {
		fclose(newFile);
		return -1;
	}

	while (current != NULL) {
		if (fprintf(newFile, "%s - %s\n", current->name, current->phoneNumber) < 0) {
			fclose(newFile);
			return -3;
		}

		current = current->nextElement;
	}

	return fclose(newFile);
}

int readFile(phoneBook* phoneBook, const char* file) {
	FILE* newFile = fopen(file, "r");
	if (newFile == NULL) {
		return -1;
	}

	char lineFromFile[MAX_LENGTH] = "";
	while (fgets(lineFromFile, MAX_LENGTH, newFile) != NULL) {
		char* token = strtok(lineFromFile, " - ");
		char name[MAX_LENGTH] = "";
		strcpy(name, token);
		token = strtok(NULL, " - ");
		char phoneNumber[MAX_LENGTH] = "";
		strcpy(phoneNumber, token);
		push(phoneBook, name, phoneNumber);
	}

	fclose(newFile);
	return 0;
}

bool isFirstBigger(char firstNumber[], char secondNumber[]) {
	if (strcmp(firstNumber, secondNumber) >= 0) {
		return true;
	} else {
		return false;
	}
}

void split(Node* phoneBook, Node** firstHalf, Node** secondHalf) {
	Node* slowPointer = phoneBook;
	Node* fastPointer = phoneBook->nextElement;
	while (fastPointer != NULL) {
		fastPointer = fastPointer->nextElement;
		if (fastPointer != NULL) {
			slowPointer = slowPointer->nextElement;
			fastPointer = fastPointer->nextElement;
		}
	}

	*firstHalf = phoneBook;
	*secondHalf = slowPointer->nextElement;
	slowPointer->nextElement = NULL;
}

Node* sortedMerge(Node* firstHalf, Node* secondHalf, bool isSortedByName) {
	if (firstHalf == NULL) {
		return secondHalf;
	}
	else if (secondHalf == NULL) {
		return firstHalf;
	}

	Node* result = NULL;
	if (isSortedByName) {
		if (isFirstBigger(firstHalf->name, secondHalf->name)) {
			result = firstHalf;
			result->nextElement = sortedMerge(firstHalf->nextElement, secondHalf, isSortedByName);
		}
		else {
			result = secondHalf;
			result->nextElement = sortedMerge(firstHalf, secondHalf->nextElement, isSortedByName);
		}
	}
	else {
		if (isFirstBigger(firstHalf->phoneNumber, secondHalf->phoneNumber)) {
			result = firstHalf;
			result->nextElement = sortedMerge(firstHalf->nextElement, secondHalf, isSortedByName);
		}
		else {
			result = secondHalf;
			result->nextElement = sortedMerge(firstHalf, secondHalf->nextElement, isSortedByName);
		}
	}

	return result;
}

void mergeSort(Node** phoneBook, bool isSortedByName) {
	if ((* phoneBook) == NULL || (* phoneBook)->nextElement == NULL) {
		return;
	}

	Node* firstHalf = NULL;
	Node* secondHalf = NULL;

	split(*phoneBook, &firstHalf, &secondHalf);
	mergeSort(&firstHalf, isSortedByName);
	mergeSort(&secondHalf, isSortedByName);

	(*phoneBook) = sortedMerge(firstHalf, secondHalf, isSortedByName);
}

