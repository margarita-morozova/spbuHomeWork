#pragma once
#include <stdbool.h>

// Pointer to the first element of the list.
struct SortedList; 

// Creates new list.
struct SortedList* createList(); 

// Adds new element to the list on the right place.
// Returns -1 when there is no list, -2 when it can't allocate memory.
int push(struct SortedList* sortedList, int value); 

// Deletes the element from the list.
// Returns -1 when there is no list, -3 when it can't find needed value in the list.
int deleteValue(struct SortedList* list, int value); 

// Deletes list.
void deleteList(struct SortedList* list); 

// Prints list, returns -1 when there is no list.
int printList(struct SortedList* list); 

// Checks is the list sorted.
bool isSorted(struct SortedList* list); 