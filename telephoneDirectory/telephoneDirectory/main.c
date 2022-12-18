#include "directory.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN_NAME 100
#define PHONE_LENGHT 18
#define YOUR_FILE "..\\directory.txt"

typedef struct {
	char name[MAX_LEN_NAME];
	char phone[PHONE_LENGHT];
} PhoneBookEntry;

int readFile(FILE* file, PhoneBookEntry *book) {
	int index = 0;
	while (!feof(file)) {
		fgets(book[index].name, MAX_LEN_NAME, file);
		fgets(book[index].phone, PHONE_LENGHT, file);
		index++;
	}
	return index;
}

int newEntry(PhoneBookEntry* book, int numberOfNewEntries, int numberOfFilesEntries) {
	int index = numberOfNewEntries + numberOfFilesEntries;
	char surname[MAX_LEN_NAME];
	printf("\nEnter the name: ");
	scanf_s("%s", book[index].name, (unsigned)_countof(book[index].name));
	printf("\nEnter the surname: ");
	scanf_s("%s", &surname, (unsigned)_countof(surname));
	strcat_s(book[index].name, MAX_LEN_NAME," ");
	strcat_s(book[index].name, MAX_LEN_NAME, surname);
	printf("\nEnter the phone number: ");
	scanf_s("%s", book[index].phone, (unsigned)_countof(book[index].phone));
	return numberOfNewEntries + 1;
}

void printAllEntries(PhoneBookEntry* book, int numberOfNewEntries, int numberOfFilesEntries) {
	printf("Your phone book now is:\n");
	for (int i = 0; i < numberOfFilesEntries; i++) {
		printf("%s %s\n", book[i].name, book[i].phone);
	}
	for (int i = numberOfFilesEntries; i < numberOfFilesEntries + numberOfNewEntries; i++) {
		printf("\n%s\n %s\n", book[i].name, book[i].phone);
	}
}

char* findPhone(PhoneBookEntry* book, char *yourName, int numberOfNewEntries, int numberOfFilesEntries) {
	for (int i = 0; i < numberOfNewEntries + numberOfFilesEntries; i++) {
		for (int j = 0; j < strlen(yourName); j++) {
			if (yourName[j] != book[i].name[j]) {
				break;
			}
			else {
				return book[i].phone;
			}
		}
	}
	printf("There is no person with this name.");
	return "";
}

char* findName(PhoneBookEntry* book, char* yourPhone, int numberOfNewEntries, int numberOfFilesEntries) {
	for (int i = 0; i < numberOfNewEntries + numberOfFilesEntries; i++) {
		for (int j = 0; j < strlen(yourPhone); j++) {
			if (yourPhone[j] != book[i].phone[j]) {
				break;
			}
			else {
				return book[i].name;
			}
		}
	}
	printf("There is no person with this phone number.");
	return "";
}

int saveAllEntries(PhoneBookEntry* book, FILE* file, int numberOfNewEntries, int numberOfFilesEntries) {
	fopen_s(&file, YOUR_FILE, "a+");
	if (file == NULL) {
		printf("file not found!");
		return 1;
	}

	for (int i = numberOfFilesEntries; i < numberOfFilesEntries + numberOfNewEntries; i++) {
		fprintf(file, "\n");
		fprintf(file, book[i].name);
		fprintf(file, "\n");
		fprintf(file, book[i].phone);
	}
	fclose(file);
	return 0;
}

int main() {

	FILE* file;
	fopen_s(&file, YOUR_FILE, "a");
	if (file == NULL) {
		printf("file not found!");
		return 0;
	}

	fclose(file);
	fopen_s(&file, YOUR_FILE, "r");
	if (file == NULL) {
		printf("file not found!");
		return 0;
	}

	PhoneBookEntry book[100];
	fseek(file, 0, SEEK_SET);
	int numberOfFilesEntries = readFile(file, book);
	int numberOfNewEntries = 0;
	fclose(file);
	int instruction = -1;
	while (true) {
		if (instruction > 5 || instruction < 0) {
			printf("Enter:\n   0 if you want to exit\n   1 if you want to add the entry\n   2 if you want to see all the entries\n   3 if you want to find the phone number using the name\n   4 if you want to find the name using the phone number\n   5 if you want to save all entries\n");
			scanf_s("%d", &instruction);
		}
		if (instruction == 0) {
			return 0;
		}
		else if (instruction == 1) {
			numberOfNewEntries = newEntry(book, numberOfNewEntries, numberOfFilesEntries);
		}
		else if (instruction == 2) {
			printAllEntries(book, numberOfNewEntries, numberOfFilesEntries);
		}
		else if (instruction == 3) {
			char name[MAX_LEN_NAME];
			char phone[PHONE_LENGHT] = "";
			printf("Enter the name and the surname: ");
			scanf_s("%s", &name, (unsigned)_countof(name));
			strcat_s(phone, PHONE_LENGHT, findPhone(book, name, numberOfNewEntries, numberOfFilesEntries));
			printf("\nThe phone number of this person is: %s", phone);
		}
		else if (instruction == 4) {
			char name[MAX_LEN_NAME] = "";
			char phone[PHONE_LENGHT];
			printf("Enter the phone: ");
			scanf_s("%s", &phone, (unsigned)_countof(phone));
			strcat_s(name, PHONE_LENGHT, findName(book, phone, numberOfNewEntries, numberOfFilesEntries));
			printf("\nThe name of this person is: %s\n", name);
		}
		else if (instruction == 5) {
			if (saveAllEntries(book, file, numberOfNewEntries, numberOfFilesEntries)) {
				printf("Can't save data");
				return -1;
			}
		}
		printf("Enter:\n   0 if you want to exit\n   1 if you want to add the entry\n   2 if you want to see all the entries\n   3 if you want to find the phone number using the name\n   4 if you want to find the name using the phone number\n   5 if you want to save all entries\n");
		scanf_s("%d", &instruction);
	}

	

	return 0;
}