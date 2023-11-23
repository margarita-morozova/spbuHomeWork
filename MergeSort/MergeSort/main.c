#include "phoneBook.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

bool pushTest() {
	struct phoneBook* newPhoneBook = createPhoneBook();
	if(push(newPhoneBook, "Alan", "+4859673") || push(newPhoneBook, "Kate", "+93058") ||
		push(newPhoneBook, "Milan", "+5284")) {
		deleteBook(newPhoneBook);
		return -1;
	}

	deleteBook(newPhoneBook);
	return 0;
}

bool readTest() {
	struct phoneBook* newPhoneBook = createPhoneBook();
	const char* file = "readTest.txt";
	if (readFile(newPhoneBook, file)) {
		return -1;
	}

	deleteBook(newPhoneBook);
	return 0;
}

bool fullTest() {
	const char* file = "fullTest.txt";
	struct phoneBook* newPhoneBook = createPhoneBook();
	if (newPhoneBook == NULL) {
		return -1;
	}

	if (readFile(newPhoneBook, file) != 0) {
		return -1;
	}

	bool isSortedByName = true;
	mergeSort(newPhoneBook, isSortedByName);
	printToFile(newPhoneBook, file);
	FILE* openFile = fopen(file, "r");
	if (openFile == NULL) {
		return -1;
	}

	char firstLineFromFile[MAX_LENGTH] = "";
	char secondLineFromFile[MAX_LENGTH] = "";
	char thirdLineFromFile[MAX_LENGTH] = "";
	fgets(firstLineFromFile, MAX_LENGTH, openFile);
	fgets(secondLineFromFile, MAX_LENGTH, openFile);
	fgets(thirdLineFromFile, MAX_LENGTH, openFile);
	if (strcmp(firstLineFromFile, "Max - +900\n") != 0 || strcmp(secondLineFromFile, "Elliot - +123456789\n") != 0 ||
		strcmp(thirdLineFromFile, "Ann - +535\n") != 0) {
		return -1;
	}
	fclose(openFile);
	deleteBook(newPhoneBook);
	return 0;
}

bool isListSortedByName(int answer) {
	return answer == 1;
}

int main() {
	if (pushTest() || readTest() || fullTest()) {
		printf("Tests failed");
		return -1;
	}

	const char* file = "test.txt";
	struct phoneBook* newPhoneBook = createPhoneBook();
	if (newPhoneBook == NULL) {
		printf("There are somee problems with memory allocation.");
		return -1;
	}

	if (readFile(newPhoneBook, file) != 0) {
		printf("Can't open your file.");
		return -1;
	}

	int answer = -1;
	printf("Enter 1 if you want to sort by name\nEnter 0 if you want to sort by number.\n");
	scanf("%d", &answer);
	while (answer != 0 && answer != 1) {
		printf("Enter 1 if you want to sort by name\nEnter 0 if you want to sort by number.\n");
		scanf("%d", &answer);
	}
	
	bool isSortedByName = isListSortedByName(answer);
	mergeSort(newPhoneBook, isSortedByName);
	printToFile(newPhoneBook, file);
	deleteBook(newPhoneBook);

	return 0;
}