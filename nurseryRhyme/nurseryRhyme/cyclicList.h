#pragma once

struct List; //pointer to the first element of the list

struct List* createList(); //creates new list

int push(struct List* sortedList, int value); //adds new element to the list on the right place
// returns -1 when there is no list, -2 when it can't allocate memory

int deleteValue(struct List* list, int value); //deletes the element from the list
// returns -1 when there is no list, -3 when it can't find needed value in the list

void deleteList(struct List* list); //deletes list

int printList(struct List* list); // prints list, returns -1 when there is no list