#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "../DoublyLinkedList.c"


void testInit() {
    DLList *list = malloc(sizeof(DLList));

    init(list);

    assert(list->first == NULL);
    assert(list->last == NULL);
    assert(list->length == 0);
}

void testIsEmpty() {
    DLList *list = malloc(sizeof(DLList));
    
    assert(isEmpty(list));
}

void testCreateNode() {
    struct Node *n = createNode();

    assert(n);
    assert(n->data == 0);
	assert(n->next == NULL);
	assert(n->prev == NULL);
}

void testInsertFirstEmptyList() {
    DLList *list = malloc(sizeof(DLList));
    struct Node *n = createNode();
    n->data = 5;

    insertFirst(list, n);

    assert(list->first->data == 5);
    assert(list->last->data == 5);
}

void testInsertFirstPopulatedList() {
    DLList *list = malloc(sizeof(DLList));
    struct Node *n = createNode();
    
    n->data = 5;
    insertFirst(list, n);

    n = createNode();
    n->data = 9;
    insertFirst(list, n);

    assert(list->first->data == 9);
}

void testInsertLastEmptyList() {
    DLList *list = malloc(sizeof(DLList));
    struct Node *n = createNode();
    n->data = 5;

    insertLast(list, n);

    assert(list->first->data == 5);
    assert(list->last->data == 5);
}

void testInsertLastPopulatedList() {
    DLList *list = malloc(sizeof(DLList));
    struct Node *n = createNode();
    
    n->data = 5;
    insertLast(list, n);

    n = createNode();
    n->data = 9;
    insertLast(list, n);

    assert(list->last->data == 9);
}

void testInsertAtEmptyList() {
    DLList *list = malloc(sizeof(DLList));
    struct Node *n = createNode();
    
    n->data = 5;
    insertAt(list, n, 0); // Insert n at pos 0

    assert(list->first->data == 5);
    assert(list->last->data == 5);
}

void testInsertAtPopulatedList() {
    DLList *list = malloc(sizeof(DLList));
    struct Node *n = createNode();
    
    n->data = 5;
    insertLast(list, n);

    n = createNode();
    n->data = 9;
    insertLast(list, n);

    n = createNode();
    n->data = 14;
    insertLast(list, n);
    
    n = createNode();
    n->data = 3;

    // [5, 9, 14] before insert at
    insertAt(list, n, 2);
    // [5, 9, 3, 14] after insert at
    
    assert(list->first->data == 5);
    assert(list->first->next->data == 9);
    assert(list->last->prev->data == 3); // Inserted
    assert(list->last->data == 14);
}

void testInsertAtNonexistentPositionEmptyList() {
    DLList *list = malloc(sizeof(DLList));
    struct Node *n = createNode();

    n->data = 5;
    insertAt(list, n, 3); // Position doesn't exist
    
    assert(list->first == NULL);
    assert(list->last == NULL);
}

void testInsertAtNonexistentPositionPopulatedList() {
    DLList *list = malloc(sizeof(DLList));
    struct Node *n = createNode();
    
    n->data = 5;
    insertLast(list, n);
    
    n = createNode();
    n->data = 14; // Won't be included
    
    insertAt(list, n, 3); // Position doesn't exist
    assert(list->first->data == 5);
    assert(list->last->data == 5);
}

void testPrintDLList() {
    DLList *list = malloc(sizeof(DLList));
    struct Node *n = createNode();
    
    n->data = 5;
    insertLast(list, n);

    n = createNode();
    n->data = 9;
    insertLast(list, n);

    n = createNode();
    n->data = 14;
    insertLast(list, n);
    
    n = createNode();
    n->data = 3;

    // [5, 9, 14]

    printDLList(list);
}


int main() {
    testInit();
    printf(".");

    testIsEmpty();
    printf(".");

    testCreateNode();
    printf(".");
    
    // insert first
    testInsertFirstEmptyList();
    printf(".");

    testInsertFirstPopulatedList();
    printf(".");

    // insert last
    testInsertLastEmptyList();
    printf(".");

    testInsertLastPopulatedList();
    printf(".");

    // insert at
    testInsertAtEmptyList();
    printf(".");
    
    testInsertAtPopulatedList();
    printf(".");
    
    testInsertAtNonexistentPositionEmptyList();
    printf(".");
    
    testInsertAtNonexistentPositionPopulatedList();
    printf(".");

    testPrintDLList();
    printf(".");

    printf("\n");
    return 0;
}