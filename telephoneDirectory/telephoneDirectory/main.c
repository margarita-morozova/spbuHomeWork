#include "directory.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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



int main() {

	FILE* file;
	fopen_s(&file, YOUR_FILE, "r");
	if (file == NULL) {
		printf("file not found!");
		return 0;
	}

	PhoneBookEntry book[100];
	fseek(file, 0, SEEK_SET);
	int numberOfEntryes = readFile(file, book);
	fclose(file);
	int instruction = -1;
	while (instruction < 0 || instruction > 5) {
		printf("Enter:\n   0 if you want to exit\n   1 if you want to add the entry\n   2 if you want to see all the entries\n   3 if you want to find the phone number using the name\n   4 if you want to find the name using the phone number\n   5 if you want to save all entries\n");
		scanf_s("%d", &instruction);
	}

	return 0;
}