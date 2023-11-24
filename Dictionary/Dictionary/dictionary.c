#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100

typedef struct {
	int key;
	char* value[MAX_LENGTH];
	struct Node* leftChild;
	struct Node* rightChild;
} Node;

typedef struct {
	Node* root;
} Dictionary;

Dictionary* createDictionary() {
	return calloc(1, sizeof(Dictionary));
}

Node* leftMostChildByNode(Node* node) {
	while (node->leftChild != NULL) {
		node = node->leftChild;
	}

	return node;
}

Node* leftMostChild(Dictionary* dictionary) {
	return leftMostChildByNode(dictionary->root);
}

void deleteChild(Node* parent, bool isLeft) {
	Node* oldChild = NULL;
	if (isLeft)
		oldChild = parent->leftChild;
	else
		oldChild = parent->rightChild;

	if (oldChild->leftChild == NULL && oldChild->rightChild == NULL) {
		if (isLeft)
			parent->leftChild = NULL;
		else
			parent->rightChild = NULL;
		free(oldChild);
		return;
	}

	if (oldChild->rightChild != NULL) {
		Node* newChild = oldChild->rightChild;
		if (newChild->leftChild == NULL) {
			oldChild->key = newChild->key;
			strcpy(oldChild->value, newChild->value);
			oldChild->rightChild = newChild->rightChild;
		}
		else {
			Node* parentOfNewChild = newChild;

			do {
				parentOfNewChild = newChild;
				newChild = newChild->leftChild;
			} while (newChild->leftChild != NULL);
			parentOfNewChild->leftChild = newChild->rightChild;

			oldChild->key = newChild->key;
			strcpy(oldChild->value, newChild->value);
		}

		free(newChild);
	}
	else {
		Node* newChild = oldChild->leftChild;
		oldChild->key = newChild->key;
		strcpy(oldChild->value, newChild->value);
		oldChild->rightChild = newChild->rightChild;
		oldChild->leftChild = newChild->leftChild;
		free(newChild);
	}
}

int* deleteValueByNode(Node* node, int key) {
	if (node->leftChild == NULL && node->rightChild == NULL)
		return NULL;
	if (node->key > key) {
		if (node->leftChild == NULL)
			return NULL;

		Node* leftChild = node->leftChild;
		if (leftChild->key == key) {
			deleteChild(node, true);
			return 0;
		}

		return deleteValueByNode(leftChild, key);
	}

	if (node->key < key) {
		if (node->rightChild == NULL)
			return NULL;

		Node* rightChild = node->rightChild;
		if (rightChild->key == key) {
			deleteChild(node, false);
			return 0;
		}

		return deleteValueByNode(rightChild, key);
	}
}

void deleteValue(Dictionary* dictionary, int key) {
	Node* root = dictionary->root;
	if (root->key == key) {
		Node * fakeParent = calloc(1, sizeof(Node));
		if (fakeParent == NULL) {
			return -1;
		}

		fakeParent->leftChild = root;
		deleteChild(fakeParent, true);
		dictionary->root = fakeParent->leftChild;
		free(fakeParent);
	}
	else
		deleteValueByNode(dictionary->root, key);
}

void deleteDictionary(Dictionary* dictionary) {
	while (dictionary->root != NULL) {
		deleteValueByNode(dictionary->root, dictionary->root->key);
	}

	free(dictionary->root);
}

int addNodeByNode(int key, char* value, Node* node) {
	if (node == NULL) {
		return -1;
	}

	if (node->leftChild == NULL && node->key > key) {
		Node* newNode = calloc(1, sizeof(Node));
		if (newNode == NULL) {
			return -1;
		}

		newNode->key = key;
		strcpy(newNode->value, value);
		node->leftChild = newNode;
		return 0;
	} else if (node->rightChild == NULL && (node->key < key)) {
		Node* newNode = calloc(1, sizeof(Node));
		if (newNode == NULL) {
			return -1;
		}

		newNode->key = key;
		strcpy(newNode->value, value);
		node->rightChild = newNode;
		return 0;
	}
	else if (node->leftChild != NULL && key < node->key) {
		addNodeByNode(key, value, node->leftChild);
		return 0;
	}
	else if (node->rightChild != NULL && key > node->key) {
		addNodeByNode(key, value, node->rightChild);
		return 0;
	}

	strcpy(node->value, value);
	return 0;
}

int addNode(Dictionary* dictionary, int key, char* value) {
	if (dictionary->root == NULL) {
		dictionary->root = calloc(1, sizeof(Node));
		if (dictionary->root == NULL) {
			return -1;
		}
	}
	if (dictionary->root->key == NULL) {
		dictionary->root->key = key;
		strcpy(dictionary->root->value, value);
		return 0;
	}

	int answer = addNodeByNode(key, value, dictionary->root);
	if (answer < 0) {
		deleteDictionary(dictionary);
		return -1;
	}

	return 0;
}

char* takeValueByNode(Node* node, int key) {
	if (node == NULL)
		return NULL;

	if (node->key == key) {
		return node->value;
	}

	if (key < node->key && node->leftChild != NULL) {
		return takeValueByNode(node->leftChild, key);
	} else if (key > node->key && node->rightChild != NULL) {
		return takeValueByNode(node->rightChild, key);
	}

	return NULL;
}

char* takeValue(Dictionary* dictionary, int key) {
	return takeValueByNode(dictionary->root, key);
}

bool isKeyInDictionary(Dictionary* dictionary, int key) {
	if (takeValueByNode(dictionary->root, key) != NULL) {
		return true;
	}

	return false;
}

Node* parentByNode(Node* currentNode, int key) {
	Node* rightChild = currentNode->rightChild;
	Node* leftChild = currentNode->leftChild;
	if ((leftChild != NULL && leftChild->key == key) ||
		(rightChild != NULL && rightChild->key == key) ){
		return currentNode;
	} else if (key > currentNode->key && rightChild != NULL) {
		parentByNode(rightChild, key);
	} else if (key < currentNode->key && leftChild != NULL) {
		parentByNode(leftChild, key);
	}

	return NULL;
}

Node* parent(Dictionary* dictionary, int key) {
	return parentByNode(dictionary->root, key);
}

void printByNode(Node* node) {
	if (node == NULL) {
		return;
	}

	printf("%d - %s\n", node->key, node->value);
	if (node->leftChild == NULL && node->rightChild == NULL) {
		return;
	}

	if (node->leftChild != NULL) {
		printByNode(node->leftChild);
	}

	if (node->rightChild != NULL) {
		printByNode(node->rightChild);
	}
}

void print(Dictionary* dictionary) {
	printByNode(dictionary->root);
}