#pragma once
#include <stdbool.h>

struct SortedList; //pointer to the first element of the list

struct SortedList* createList(); //creates new list

int push(struct SortedList* sortedList, int value); //adds new element to the list on the right place
// returns -1 when there is no list, -2 when it can't allocate memory

int deleteValue(struct SortedList* list, int value); //deletes the element from the list
// returns -1 when there is no list, -3 when it can't find needed value in the list

void deleteList(struct SortedList* list); //deletes list

int printList(struct SortedList* list); // prints list, returns -1 when there is no list

bool isSorted(struct SortedList* list); // checks is the list sorted