#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN_NAME 100
#define PHONE_LENGTH 18
#define YOUR_FILE "..\\directory.txt"

typedef struct {
	char name[MAX_LEN_NAME];
	char phone[PHONE_LENGTH];
} PhoneBookEntry;

int newEntry(PhoneBookEntry* book, int numberOfNewEntries, int numberOfFilesEntries) {
	int index = numberOfNewEntries + numberOfFilesEntries;
	char surname[MAX_LEN_NAME] = {'\0'};
	printf("\nEnter the name: ");
	scanf_s("%s", book[index].name, (unsigned)sizeof(book[index].name));
	printf("\nEnter the surname: ");
	scanf_s("%s", &surname, (unsigned)sizeof(surname));
	strcat_s(book[index].name, MAX_LEN_NAME, " ");
	strcat_s(book[index].name, MAX_LEN_NAME, surname);
	strcat_s(book[index].name, MAX_LEN_NAME, "\n");
	printf("\nEnter the phone number: ");
	scanf_s("%s", book[index].phone, (unsigned)sizeof(book[index].phone));
	return numberOfNewEntries + 1;
}

void printAllEntries(PhoneBookEntry* book, int numberOfNewEntries, int numberOfFilesEntries) {
	printf("Your phone book now is:\n");
	for (int i = 0; i < numberOfFilesEntries + numberOfNewEntries; i++) {
		printf("%s %s\n", book[i].name, book[i].phone);
	}
}

char* findPhone(PhoneBookEntry* book, char* yourName, int numberOfNewEntries, int numberOfFilesEntries) {
	bool flag = true;
	for (int i = 0; i < numberOfNewEntries + numberOfFilesEntries; i++) {
		int lenName = strlen(yourName);
		for (int j = 0; j < lenName; j++) {
			if (yourName[j] != book[i].name[j]) {
				flag = false;
				break;
			} else {
				flag = true;
			}
		}

		if (flag) {
			return book[i].phone;
		}
	}

	printf("There is no person with this name.\n");
	return "";
}

char* findName(PhoneBookEntry* book, char* yourPhone, int numberOfNewEntries, int numberOfFilesEntries) {
	bool flag = true;
	for (int i = 0; i < numberOfNewEntries + numberOfFilesEntries; i++) {
		for (int j = 0; j < strlen(yourPhone); j++) {
			if (yourPhone[j] != book[i].phone[j]) {
				flag = false;
				break;
			}
			else {
				flag = true;
			}
		}

		if (flag) {
			return book[i].name;
		}
	}

	printf("There is no person with this phone number.\n");
	return "";
}
