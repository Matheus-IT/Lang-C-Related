#include <stdio.h>
#include <stdlib.h>

int LENGTH;

void show(int vect[]) {
	for (int i = 0; i < LENGTH; i++) {
		printf(" %d ", vect[i]);
	}
	printf("\n");
}

void storeAscendant(int vect[], int n1, int n2) {
	for (int i = n1, j = 0; i <= n2; i++, j++) {
		vect[j] = i;
	}
}

void storeDescendant(int vect[], int n1, int n2) {
	for (int i = n1, j = 0; i >= n2; i--, j++) {
		vect[j] = i;
	}
}

int main() {
	int n1, n2;

	printf(" Type the 1o number: ");
	scanf(" %d", &n1);
	printf(" Type the 2o number: ");
	scanf(" %d", &n2);
	
	int *vect = NULL;

	if (n1 < n2) {
		LENGTH = (n2 - n1) + 1;
		vect = (int *) malloc(LENGTH * sizeof(int));
		storeAscendant(vect, n1, n2);
	}
	else {
		LENGTH = (n1 - n2) + 1;
		vect = (int *) malloc(LENGTH * sizeof(int));
		storeDescendant(vect, n1, n2);
	}

	show(vect);
	free(vect);
	return 0;
}