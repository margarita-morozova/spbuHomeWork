#pragma once

#define MAX_LEN_NAME 100
#define PHONE_LENGTH 18
#define YOUR_FILE "..\\directory.txt"

// structure of phone book
typedef struct {
	char name[MAX_LEN_NAME];
	char phone[PHONE_LENGTH];
} PhoneBookEntry;

// creates new entry, saves it in structure, returns the number of entries
int newEntry(PhoneBookEntry* book, int numberOfNewEntries, int numberOfFilesEntries); 

// prints all entries from the structure
void printAllEntries(PhoneBookEntry* book, int numberOfNewEntries, int numberOfFilesEntries); 

// finds the phone number using the name
char* findPhone(PhoneBookEntry* book, char* yourName, int numberOfNewEntries, int numberOfFilesEntries); 

// finds the name using the phone number
char* findName(PhoneBookEntry* book, char* yourPhone, int numberOfNewEntries, int numberOfFilesEntries); 