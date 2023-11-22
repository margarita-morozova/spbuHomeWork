#pragma once
#include <stdbool.h>

// Pointer to the first element of the phone book.
struct phoneBook;

// Creates new phone book.
struct phoneBook* createPhoneBook();

// Adds new element to the phone book
// Returns -1 when there is no phone book, -2 when it can't allocate memory.
int push(struct phoneBook* phoneBook, char name[], char phoneNumber[]);

// Deletes phone book
void deleteBook(struct phoneBook* phoneBook);

// Prints phone book to file.
// Returns -1 when there is no phone book, -2 when it can' open file.
// Returns -3 when it can't write to file.
int printToFile(struct phoneBook* phoneBook, const char* file);


// Reads the file and adds data to the phone book.
// Returns -1 when there is no phone book.
int readFile(struct phoneBook* phoneBook, const char* file);

// Checks if the first string bigger than the second one.
bool isFirstBigger(char firstNumber[], char secondNumber[]);

// Splits one list into two using fast&slow pointer strategy.
void split(struct Node* phoneBook, struct Node** firstHalf, struct Node** secondHalf);

// Sorts and merges two lists by name or by number.
// Returns one sorted list.
struct Node* sortedMerge(struct Node* firstHalf, struct Node* secondHalf, bool isSortedByName);

// Uses merge sort on the list.
int realMergeSort(struct phoneBook** phoneBook, bool isSortedByName);

// Takes the first node from the phone book.
void mergeSort(struct phoneBook* phoneBook, bool isSortedByName);
