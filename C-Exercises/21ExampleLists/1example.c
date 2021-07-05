#include <stdio.h>

#define MAX 10


typedef struct {
	int items[MAX];
	int index;
} List;


void initialize(List *list) {
	list->index = 0;
}


void shiftRight(List *list, int pos) {
	for (int i = list->index; i > pos; i--)
		list->items[i] = list->items[i-1];
	list->items[pos] = 0;
	list->index++;
}

void shiftLeft(List *list, int pos) {
	for (int i = pos; i < list->index; i++)
		list->items[i] = list->items[i+1];
	list->index--;
}


void insertBegin(List *list, int n) {
	if (list->index < MAX) {
		shiftRight(list, 0);
		list->items[0] = n;
	}
}


void insertEnd(List *list, int n) {
	if (list->index < MAX) {
		list->items[list->index] = n;
		list->index++;
	}
}


void insertAt(List *list, int val, int pos) {
	if (list->index < MAX) {
		shiftRight(list, pos);
		list->items[pos] = val;
	}
}


void removeBegin(List *list) {
	shiftLeft(list, 0);
}


void removeLast(List *list) {
	list->index--;
}


void removeAt(List *list, int pos) {
	if (list->index < MAX)
		shiftLeft(list, pos);
}


void printList(List *list) {
	printf("[");

	for (int i = 0; i < list->index; i++)
		if (i == list->index - 1)
			printf("%d", list->items[i]);
		else
			printf("%d, ", list->items[i]);

	printf("]");
	printf("\n");
}


int main() {
	List list;

	initialize(&list);

	for (int i = 0; i < 5; i++)
		insertEnd(&list, i);

	printf("\n\n");
	printList(&list);

	insertBegin(&list, 2);
	printList(&list);

	insertEnd(&list, 10);
	printList(&list);
	
	insertAt(&list, 12, 2);
	printList(&list);

	removeBegin(&list);
	printList(&list);

	removeLast(&list);
	printList(&list);

	removeAt(&list, 3);
	printList(&list);
	return 0;
}