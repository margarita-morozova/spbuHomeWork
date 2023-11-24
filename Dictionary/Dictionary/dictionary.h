#pragma once

#include <stdbool.h>

// Pointer to the first element of the book.
struct Dictionary;

// Creates new dictionary.
struct Dictionary* createDictionary();

// Takes the root of the dictionary and uses addNodeByNode function to add node.
int addNode(struct Dictionary* dictionary, int key, char* value);

// Takes the root of the dictionary and uses takeValueByNode function.
// Finds in dictionary and returns value by key.
// Returns NULL if there is no needed key.
char* takeValue(struct Dictionary* dictionary, int key);

// Checks is there needed key in the dictionary.
bool isKeyInDictionary(struct Dictionary* dictionary, int key);

// Takes the root of the dictionary and uses leftMostChildByNode function.
// Finds the smallest key in the sub-tree
struct Node* leftMostChild(int key, struct Dictionary* dictionary);

// Takes the root of the dictionary and uses deleteValueByNode function.
// Deletes node from the dictionary by key.
void deleteValue(struct Dictionary* dictionary, int key);

// Takes the root of the dictionary and uses parentByNode function.
// Finds the parent of the taken node.
struct Node* parent(struct Dictionary* dictionary, int key);

// Deletes the dictionary.
void deleteDictionary(struct Dictionary* dictionary);

// Prints the dictionary
void print(struct Dictionary* dictionary);