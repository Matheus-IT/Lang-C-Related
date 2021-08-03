#include "./DoublyLinkedList.c"


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