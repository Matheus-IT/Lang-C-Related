#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


void printVector(int *v, unsigned length) {
	printf("\nVetor: ");
	for (int i = 0; i < length; i++) {
		printf("%d ", *(v+i));
	}
	printf("\n");
}

int main() {
	unsigned length = 0;
	int *pt = (int *) malloc(sizeof(int));
	int op = 0;

	do {
		printf("Digite um valor: ");
		scanf(" %d", &pt[length]);
		pt = realloc(pt, ++length+1 * sizeof(int));

		printf("Mais um? [1 ou 0] >> ");
		scanf(" %d", &op);
	} while(op);
	
	printVector(pt, length);
	return(0);
}
