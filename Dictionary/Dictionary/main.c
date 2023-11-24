#include "dictionary.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100

bool test() {
	struct Dictionary* dictionary = createDictionary();
	if (dictionary == NULL)
		return false;

	if (addNode(dictionary, 10, "Kate") != 0)
		return false;
	if (addNode(dictionary, 3, "Mike") != 0)
		return false;
	if (addNode(dictionary, 20, "Elliot") != 0)
		return false;
	if (addNode(dictionary, 25, "Sam") != 0)
		return false;
	
	if (strcmp(takeValue(dictionary, 10), "Kate") != 0)
		return false;
	if (strcmp(takeValue(dictionary, 25), "Sam") != 0)
		return false;

	deleteValue(dictionary, 10);
	if (takeValue(dictionary, 10) != NULL)
		return false;
	deleteValue(dictionary, 3);
	if (takeValue(dictionary, 3) != NULL)
		return false;
	deleteValue(dictionary, 25);
	if (takeValue(dictionary, 25) != NULL)
		return false;
	deleteValue(dictionary, 20);
	if (takeValue(dictionary, 20) != NULL)
		return false;

	deleteDictionary(dictionary);
	return true;
}

void instruction() {
	printf("Enter 0 to add value by key\n"
		"Enter 1 to get the value by key\n"
		"Enter 2 to check if the the key is in dictionary"
		"Enter 3 to delete the value by key.\n"
		"Enter 4 to print the dictionary\n"
		"Enter 5 to exit\n");
}

int main() {
	if (!test()) {
		printf("There are some problems in the program.");
		return -1;
	}

	int answer = -1;
	instruction();
	scanf("%d", &answer);
	while (answer < 0 || answer > 5) {
		printf("There is no such command.\n");
		instruction();
		scanf("%d", &answer);
	}
	
	struct Dictionary* dictionary = createDictionary();
	if (dictionary == NULL) {
		printf("\nCan't allocate memory.");
		return -1;
	}

	while (answer >= 0 && answer < 5) {
		if (answer == 0) {
			int key = -9999;
			char value[MAX_LENGTH] = "";
			printf("\nEnter the key: ");
			scanf("%d", &key);
			printf("\nEnter the value: ");
			scanf("%s", value);
			if (addNode(dictionary, key, value) != 0) {
				printf("\nThere are some problems in the program\n");
				return -1;
			}

			printf("\nThe value added to the dictionary\n");
		} else if (answer == 1) {
			int key = -9999;
			printf("\nEnter the key: ");
			scanf("%d", &key);
			char* value = takeValue(dictionary, key);
			if (value == NULL) {
				printf("\nThere is no such key in the dictionary.\n");
			}
			else {
				printf("\nThe value stored with the key %d is %s\n", key, value);
			}
		} else if (answer == 2) {
			int key = -9999;
			printf("\nEnter the key: ");
			scanf("%d", &key);
			if (isKeyInDictionary(dictionary, key)) {
				printf("\nThe value is in dictionary.\n");
			}
			else {
				printf("\nThe value is not in dictionary.\n");
			}
		} else if (answer == 3) {
			int key = -9999;
			printf("\nEnter the key: ");
			scanf("%d", &key);
			deleteValue(dictionary, key);
			printf("The value deleted");
		} else if (answer == 4) {
			print(dictionary);
		} else if (answer == 5) {
			break;
		}

		instruction();
		scanf("%d", &answer);
	}

	deleteDictionary(dictionary);
	return 0;
}