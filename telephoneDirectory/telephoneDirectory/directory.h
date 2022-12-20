#pragma once

#define MAX_LEN_NAME 100
#define PHONE_LENGHT 18

typedef struct {
	char name[MAX_LEN_NAME];
	char phone[PHONE_LENGHT];
} PhoneBookEntry; // structure of phone book

int newEntry(PhoneBookEntry* book, int numberOfNewEntries, int numberOfFilesEntries); // creates new entry and saves it in structure

void printAllEntries(PhoneBookEntry* book, int numberOfNewEntries, int numberOfFilesEntries); // prints all entries from the structure

char* findPhone(PhoneBookEntry* book, char* yourName, int numberOfNewEntries, int numberOfFilesEntries); // finds the phone number using the name

char* findName(PhoneBookEntry* book, char* yourPhone, int numberOfNewEntries, int numberOfFilesEntries); // finds the name using the phone number