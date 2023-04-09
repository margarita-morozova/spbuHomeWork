#pragma once

#include <stdbool.h>

struct List; //pointer to the first element of the list

struct List* createList(); //creates new list

int push(struct List* sortedList, int value); //adds new element to the list on the right place

int deleteValue(struct List* list, int value); //deletes the element from the list

void deleteList(struct List* list); //deletes list

int printList(struct List* list); // prints list

bool isRightAnswer(int rightAnswer, struct List* list); // checks the answer for tests and deletes list