#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
};

typedef struct {
	int length;
	struct Node *first;
	struct Node *last;
} DLList;


void init(DLList *list) {
	list->first = NULL;
	list->last = NULL;
	list->length = 0;
}

bool isEmpty(DLList *list) {
	/* 
	 * Verify if a DEList is empty */
	return list->length == 0; 
}

struct Node* createNode() {
	struct Node *node = (struct Node*) malloc(sizeof(struct Node));
	node->data = 0;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

void insertFirst(DLList *list, struct Node *newNode) {
	/*
	 * If the list is empty, the new node will be the 
	 * first and the last */
	if (isEmpty(list)) {
		list->first = newNode;
		list->last = newNode;
		list->length++;
		return;
	}

	list->first->prev = newNode;
	list->first = newNode;
	list->length++;
}

void insertLast(DLList *list, struct Node *newNode) {
	/*
	 * If the list is empty, the new node will be the 
	 * first and the last */
	if (isEmpty(list)) {
		list->first = newNode;
		list->last = newNode;
		list->length++;
		return;
	}

	list->last->next = newNode;
	list->last = newNode;
	list->length++;
}

void insertAt(DLList *list, struct Node *newNode, int position) {
	if (isEmpty(list)) {
		list->first = newNode;
		list->last = newNode;
		list->length++;
		return;
	}

	struct Node *aux = list->first;

	int i = 0;
	while (i != position && aux != NULL) {
		aux = aux->next;
		i++;
	}

	if (aux != NULL) {
		if (position == 0) {
			newNode->next = aux;
			aux->prev = newNode;
			list->length++;
			return;
		}
		newNode->next = aux;
		aux->prev = newNode;
		aux->prev->next = newNode;
		list->length++;
	}
}

void printDLList(DLList *list) {
	// Need to fix this function
	struct Node *el = list->first;
	
	while (el->next != NULL) {
		printf("%d ", el->data);
		el = el->next;
	}
	printf("\n");
}


int main() {
	DLList *list = malloc(sizeof(DLList));

	init(list);

	struct Node *newItem = createNode();
	newItem->data = 5;

	insertLast(list, newItem);

	printf("\n First: %d", list->first->data);
	printf("\n Last: %d", list->last->data);
	printf("\n List: ");
	printDLList(list);

	newItem = createNode();
	newItem->data = 9;

	insertLast(list, newItem);

	printf("\n First: %d", list->first->data);
	printf("\n Last: %d", list->last->data);
	printf("\n List: ");
	printDLList(list);

	newItem = createNode();
	newItem->data = 13;

	insertFirst(list, newItem);

	printf("\n First: %d", list->first->data);
	printf("\n Last: %d", list->last->data);
	printf("\n List: ");
	printDLList(list);

	newItem = createNode();
	newItem->data = 19;

	insertAt(list, newItem, 13);

	printf("\n First: %d", list->first->data);
	printf("\n Last: %d", list->last->data);
	printf("\n List: ");
	printDLList(list);

	return 0;
}