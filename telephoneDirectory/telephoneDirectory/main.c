#include "directory.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct PhoneBookEntry;

int readFile(FILE* file, PhoneBookEntry* book) {
	int index = 0;
	while (!feof(file)) {
		fgets(book[index].name, MAX_LEN_NAME, file);
		fgets(book[index].phone, PHONE_LENGTH, file);
		index++;
	}
	return index;
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
		fprintf(file, book[i].phone);
	}

	fclose(file);
	return 0;
}

int main() {
	FILE* file;

	fopen_s(&file, YOUR_FILE, "r");
	if (file == NULL) {
		printf("file not found!");
		return 0;
	}

	PhoneBookEntry book[100];
	int numberOfFilesEntries = readFile(file, book);
	int numberOfNewEntries = 0;
	fclose(file);
	int instruction = -1;
	while (true) {
		if (instruction > 5 || instruction < 0) {
			printf("Enter:\n   0 if you want to exit\n   1 if you want to add the entry");
			printf("\n   2 if you want to see all the entries\n   3 if you want to find the phone number using the name\n");
			printf("   4 if you want to find the name using the phone number\n   5 if you want to save all entries\n");
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
			char name[MAX_LEN_NAME] = "";
			char surname[MAX_LEN_NAME] = "";
			char phone[PHONE_LENGTH] = "";
			printf("Enter the name: ");
			scanf_s("%s", &name, (unsigned)sizeof(name));
			printf("Enter the surname: ");
			scanf_s("%s", &surname, (unsigned)sizeof(surname));
			strcat_s(name, MAX_LEN_NAME, " ");
			strcat_s(name, MAX_LEN_NAME, surname);
			strcat_s(phone, PHONE_LENGTH, findPhone(book, name, numberOfNewEntries, numberOfFilesEntries));
			if (strcmp(phone, "") > 0) {
				printf("\nThe phone number of this person is: %s", phone);
			}
		}
		else if (instruction == 4) {
			char name[MAX_LEN_NAME] = "";
			char phone[PHONE_LENGTH];
			printf("Enter the phone: ");
			scanf_s("%s", &phone, (unsigned)sizeof(phone));
			strcat_s(name, PHONE_LENGTH, findName(book, phone, numberOfNewEntries, numberOfFilesEntries));
			if (strcmp(name, "") > 0) {
				printf("\nThe name of this person is: %s\n", name);
			}
		}
		else if (instruction == 5) {
			if (saveAllEntries(book, file, numberOfNewEntries, numberOfFilesEntries)) {
				printf("Can't save data");
				return -1;
			}

			numberOfFilesEntries += numberOfNewEntries;
			numberOfNewEntries = 0;
		}

		printf("Enter:\n   0 if you want to exit\n   1 if you want to add the entry");
		printf("\n   2 if you want to see all the entries\n   3 if you want to find the phone number using the name\n");
		printf("   4 if you want to find the name using the phone number\n   5 if you want to save all entries\n");
		scanf_s("%d", &instruction);
	}

	return 0;
}