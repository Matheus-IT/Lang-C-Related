#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// ---------------------- GLOBALS --------------------------
#define PLATE_LENGTH 8
#define SPEED_LIMIT 60 // Km/h
#define PAYED_PER_KM 5 // R$5.00 payed per km beyond the speed limit
#define MAX_FINE_AMOUNT 190

typedef struct {
	int day;
	int month;
	int year;
} Date;

struct HighSpeedFine {
	int id;
	char licensePlate[PLATE_LENGTH];
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

void printSpeedFine(struct HighSpeedFine *fine) {
	printf("id%d: %s R$%d %dkm/h [%d/%d/%d] \n", fine->id, 
								   	   			 fine->licensePlate,
								   	   			 fine->fineAmount,
									   			 fine->speed,
									   			 fine->date->day,
									   			 fine->date->month,
									   			 fine->date->year);
}

void printLinkedList(struct LinkedList *list) {
	/* Print list with format using square brackets */
	if (isEmpty(list))
		return;

	struct HighSpeedFine *el = list->first;

	do {
		printSpeedFine(el);
		el = el->next;
	} while (el != NULL);
}


// ---------------- SPEED FINE OPERATIONS ------------------
void registerSpeedFine(struct HighSpeedFine *fine,
					   char licensePlate[],
					   int speed,
					   Date occurrenceDate) {
	if (strlen(licensePlate) == 7 && speed > 0) {
		strcpy(fine->licensePlate, licensePlate);
		fine->speed = speed;

		fine->date->day = occurrenceDate.day;
		fine->date->month = occurrenceDate.month;
		fine->date->year = occurrenceDate.year;
	} else {
		printf("Valor incorreto %s - %dkm/h\n", licensePlate, speed);
	}
}

void calculateFine(struct HighSpeedFine *fine) {
	int val = (fine->speed - SPEED_LIMIT) * PAYED_PER_KM;

	// Limit the amount to be payed
	if (val > MAX_FINE_AMOUNT)
		val = MAX_FINE_AMOUNT;

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

	char plate[PLATE_LENGTH];
	int speed = 0;
	Date date;

	struct HighSpeedFine *newSpeedFine;
	int op = 0;

	do {
		// Validate entries for new speed fine
		do {
			printf("Digite a placa do veiculo[sete caracteres]: ");
			scanf("%s", plate);

			if (strlen(plate) != PLATE_LENGTH-1)
				puts("\nPlaca incorreta, digite novamente!");
		} while(strlen(plate) != PLATE_LENGTH-1);

		do {
			printf("Qual velocidade passou pelo semaforo: ");
			scanf("%d", &speed);

			if (speed == 0)
				puts("O carro precisa estar andando, digite novamente!");
			else if (speed < 0)
				puts("O valor tem que ser positivo, digite novamente!");
		} while(speed <= 0);

		do {
			printf("Qual a data da ocorrencia[DD MM AAAA]: ");
			scanf("%d %d %d", &date.day, &date.month, &date.year);

			if (date.day < 0 || date.month < 0 || date.year < 0)
				puts("Invalido, data com valor negativo, tente novamente!");
			else if (date.day == 0 || date.month == 0 || date.year == 0)
				puts("Valor invalido, as datas comecam sempre com 1!");
		} while(date.day <= 0 || date.month <= 0 || date.year <= 0);

		newSpeedFine = createNode();
		registerSpeedFine(newSpeedFine, plate, speed, date);
		calculateFine(newSpeedFine);
		insertLast(list, newSpeedFine);

		printLinkedList(list);

		printf("Registrar mais um? [1-sim/0-nao]: ");
		scanf("%d", &op);
	} while (op == 1);
	

	free(list);
	return 0;
}