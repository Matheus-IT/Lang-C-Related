#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct Person {
    char name[40];
    unsigned age;
    struct Person *next;
} Person;


typedef struct {
    int length;
    Person *top;
} Stack;


Person * createPerson() {
    Person *person = malloc(sizeof(Person));
    person->next = NULL;
}

void initStack(Stack *stack) {
    stack->top = NULL;
    stack->length = 0;
}


int main() {
    // FIFO = Fila
    // LIFO = Pilha
    // Lista <-

    /*
     * Real Madrid, Roma, Barcelona, Bayern, Chelsea
     *
     * Barcelona <-> Chelsea <-> Bayern <-> Real Madrid <-> Roma
     */
    return 0;
}