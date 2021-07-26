#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// ---------------------- GLOBALS --------------------------
#define SPEED_LIMIT 60 // Km/h
#define PAYED_PER_KM 5 // R$5.00 payed per km beyond the speed limit

typedef struct {
	int day;
	int month;
	int year;
} Date;

struct HighSpeedFine {
	int id;
	char licensePlate[8];
	int speed;
	Date *date;
	int fineAmount;

	struct HighSpeedFine *next;
};

struct LinkedList {
	int length;
	struct HighSpeedFine *first;
	struct HighSpeedFine *last;
};


// ----------------- HELPER FUNCTIONS ----------------------
void init(struct LinkedList *list) {
	list->first = NULL;
	list->last = NULL;
	list->length = 0;
}

bool isEmpty(struct LinkedList *list) {
	/* Verify if a LinkedList is empty */
	return list->length == 0; 
}

int generateId() {
	static int id = 0;
	return ++id;
}

struct HighSpeedFine* createNode() {
	struct HighSpeedFine *node = malloc(sizeof(struct HighSpeedFine));
	node->id = generateId();
	strcpy(node->licensePlate, "");
	node->speed = 0;

	node->date = malloc(sizeof(Date));
	node->date->day = 0;
	node->date->month = 0;
	node->date->year = 0;
	
	node->fineAmount = 0;
	node->next = NULL;
	return node;
}

void printLinkedList(struct LinkedList *list) {
	/* Print list with format using square brackets */
	if (isEmpty(list))
		return;

	struct HighSpeedFine *el = list->first;
	printf("[");

	do {
		if (el->next != NULL) // If it's not the last, print with comma
			printf("id%d: %s R$%d %dkm/h, \n", el->id, 
								   	  		   el->licensePlate,
								   	  		   el->fineAmount,
									  		   el->speed);
		else
			printf("id%d: %s R$%d %dkm/h", el->id, 
							   			   el->licensePlate,
							   			   el->fineAmount,
										   el->speed);
		
		el = el->next;
	} while (el != NULL);

	printf("]\n");
}


// ---------------- SPEED FINE OPERATIONS ------------------
void registerSpeedFine(struct HighSpeedFine *fine,
						  char licensePlate[],
						  int speed) {
	if (strlen(licensePlate) == 7 && speed > 0) {
		strcpy(fine->licensePlate, licensePlate);
		fine->speed = speed;
	} else {
		printf("Invalid speed fine %s - %dkm/h\n", licensePlate, speed);
	}
}

void calculateFine(struct HighSpeedFine *fine) {
	int val = (fine->speed - SPEED_LIMIT) * PAYED_PER_KM;

	if (val > 0)
		fine->fineAmount = val;
}


// ---------------- LINKED LIST OPERATIONS -----------------
void insertFirst(struct LinkedList *list, struct HighSpeedFine *newNode) {
	/* If the list is empty, the new node will be the 
	 * first and the last */
	if (isEmpty(list)) {
		list->first = newNode;
		list->last = newNode;
		list->length++;
		return;
	}

	newNode->next = list->first;
	list->first = newNode;
	list->length++;
}

void insertLast(struct LinkedList *list, struct HighSpeedFine *newNode) {
	/* If the list is empty, the new node will be the 
	 * first AND the last */
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

void insertAt(struct LinkedList *list,
			  struct HighSpeedFine *newNode,
			  int refId) {
    /* Insert a new node at a particular position given a
	   referential id */
	struct HighSpeedFine *aux = list->first;

	while (aux->id != refId && aux != NULL) {
		aux = aux->next;
	}
	if (aux != NULL) {
		newNode->next = aux->next;
		aux->next = newNode;
		list->length++;
	}
}

void removeFirst(struct LinkedList *list) {
	/* Remove the first element and liberate memory */
	struct HighSpeedFine *old = list->first;

	// Now the second element will be the first
	list->first = list->first->next;
	list->length--;

	// liberate allocated memory of old element
	free(old);
}

void removeLast(struct LinkedList *list) {
	/* Remove the last element and liberate memory */
	struct HighSpeedFine *el = list->first;

	while (el->next->next != NULL) {		
		el = el->next;
	}
	struct HighSpeedFine *old = el->next;

	// Since now "el" is the penultimate list value, the last
	// will be disregarded
	el->next = NULL;

	// liberate allocated memory of old element
	free(old);
}

void removeAt(struct LinkedList *list, int refId) {
	/* Remove node at a particular position given a
	   referential value */
	struct HighSpeedFine *aux = list->first;

	if (isEmpty(list))
		return;

	// If the first node is the one just remove it
	if (aux->id == refId) {
		removeFirst(list);
		return;
	}

	// If the last node is the one skip the search
	if (list->last->id == refId) {
		removeLast(list);
		return;
	}

	// If the next value is the one I'm looking just remove the link
	while (aux->next->id != refId && aux->next != NULL) {
		aux = aux->next;
	}
	if (aux->next != NULL) {
		struct HighSpeedFine *old = aux->next;

		// The following value of the next will now be referenced
		aux->next = aux->next->next;
		list->length--;
		// liberate allocated memory of old element
		free(old);
	}
}


int main() {
	struct LinkedList *list = malloc(sizeof(struct LinkedList));
	init(list);

	struct HighSpeedFine *newItem = createNode();
	registerSpeedFine(newItem,  "1234abc", 59);
	calculateFine(newItem);
	insertFirst(list, newItem);

	newItem = createNode();
	registerSpeedFine(newItem, "1234acb", 60);
	calculateFine(newItem);
	insertLast(list, newItem);

	newItem = createNode();
	registerSpeedFine(newItem, "1234cba", 61);
	calculateFine(newItem);
	insertLast(list, newItem);

	newItem = createNode();
	registerSpeedFine(newItem, "1234cbb", 65);
	calculateFine(newItem);
	insertAt(list, newItem, 2);
	printLinkedList(list);

	free(list);
	return 0;
}