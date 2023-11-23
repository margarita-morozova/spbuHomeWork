#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	int key;
	char* value;
	struct Node* leftChild;
	struct Node* rightChild;
} Node;

typedef struct {
	Node* root;
} Dictionary;

Dictionary* createDictionary() {
	return calloc(1, sizeof(Dictionary));
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
		newNode->leftChild = NULL;
		newNode->rightChild = NULL;
		node->leftChild = newNode;
		return 0;
	} else if (node->rightChild == NULL && (node->key < key)) {
		Node* newNode = calloc(1, sizeof(Node));
		if (newNode == NULL) {
			return -1;
		}

		newNode->key = key;
		strcpy(newNode->value, value);
		newNode->leftChild = NULL;
		newNode->rightChild = NULL;
		node->rightChild = newNode;
		return 0;
	}
	else if (node->leftChild = !NULL && key < node->key) {
		addNodeByNode(key, value, node->leftChild);
	}
	else if (node->rightChild != NULL && key > node->key) {
		addNodeByNode(key, value, node->rightChild);
	}

	strcpy(node->value, value);
	return 0;
}

int addNode(Dictionary* dictionary, int key, char* value) {
	int answer = addNodeByNode(key, value, dictionary->root);
	if (answer < 0) {
		deleteDictionary(dictionary);
		return -1;
	}

	return 0;
}

char* takeValueByNode(Node* node, int key) {
	if (node->key == key) {
		return node->value;
	}

	char* answer = "";
	if (key < node->key && node->leftChild != NULL) {
		answer = takeValueByNode(node->leftChild, key);
	} else if (key > node->key && node->rightChild != NULL) {
		answer = takeValueByNode(node->rightChild, key);
	}

	return NULL;
}

char* takeValue(Dictionary* dictionary, int key) {
	return takeValueByNode(dictionary->root, key);
}

bool isKeyInDictionaryByNode(Dictionary* dictionary, int key) {
	if (takeValueByNode(dictionary->root, key) != NULL) {
		return true;
	}

	return false;
}

Node* leftMostChildByNode(Node* node, int key) {
	while (node->leftChild != NULL) {
		node = node->leftChild;
	}

	return node;
}

Node* leftMostChild(int key, Dictionary* dictionary) {
	return leftMostChildByNode(dictionary->root, key);
}

Node* deleteValueByNode(Node* node, int key) {
	if (node == NULL) {
		return node;
	}

	if (key < node->key) {
		deleteValueByNode(node->leftChild, key);
	} else if (key > node->key) {
		deleteValueByNode(node->rightChild, key);
	} else if (node->leftChild != NULL && node->rightChild != NULL) {
		Node* rightChild = node->rightChild;
		Node* newNode = leftMostChildByNode(node, rightChild->key);
		node->key = newNode->key;
		node->rightChild = deleteValueByNode(node->rightChild, node->key);
	} else if (node->leftChild != NULL) {
		node = node->leftChild;
	} else if (node->rightChild != NULL) {
		node = node->rightChild;
	}
	else {
		node = NULL;
	}

	return node;
}

int deleteValue(Dictionary* dictionary, int key) {
	return deleteValueByNode(dictionary->root, key);
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

int deleteDictionary(Dictionary* dictionary) {
	while (dictionary->root != NULL) {
		deleteValueByNode(dictionary->root, dictionary->root->key);
	}

	free(dictionary->root);
}