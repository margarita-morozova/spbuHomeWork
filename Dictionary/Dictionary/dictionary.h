#pragma once

#include <stdbool.h>

// Pointer to the first element of the book.
struct Dictionary;

// Creates new dictionary.
Dictionary* createDictionary();

// Adds new node to the dictionary.
int addNodeByNode(int key, char* value, struct Node* node);

// Takes the root of the dictionary and uses addNodeByNode function.
int addNode(struct Dictionary* dictionary, int key, char* value);

// Finds in dictionary and returns value by key.
// Returns NULL if there is no needed key.
char* takeValueByNode(struct Node* node, int key);

// Takes the root of the dictionary and uses takeValueByNode function.
char* takeValue(struct Dictionary* dictionary, int key);

// Checks is there needed key in the dictionary.
bool isKeyInDictionaryByNode(struct Dictionary* dictionary, int key);

// Finds the smallest key in the sub-tree
struct Node* leftMostChildByNode(struct Node* node, int key);

// Takes the root of the dictionary and uses leftMostChildByNode function.
struct Node* leftMostChild(int key, struct Dictionary* dictionary);

// Deletes node from the dictionary by key.
struct Node* deleteValueByNode(struct Node* node, int key);

// Takes the root of the dictionary and uses deleteValueByNode function.
void deleteValue(struct Dictionary* dictionary, int key);

// Finds the parent of the taken node.
struct Node* parentByNode(struct Node* currentNode, int key);

// Takes the root of the dictionary and uses parentByNode function.
Node* parent(Dictionary* dictionary, int key);

// Deletes the dictionary.
void deleteDictionary(Dictionary* dictionary);