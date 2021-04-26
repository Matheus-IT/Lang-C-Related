#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LENGTH;

void show(int vect[]) {
	for (int i = 0; i < LENGTH; i++) {
		printf(" %d ", vect[i]);
	}
	printf("\n");
}

int calcHighest(int vect[]) {
	int heighest = NULL;

	for (int i = 0; i < LENGTH; i++) {
		if (vect[i] > heighest) {
			heighest = vect[i];
		}
	}
	return heighest;
}

int calcLowest(int vect[]) {
	int lowest = vect[0];

	for (int i = 1; i < LENGTH; i++) {
		if (vect[i] < lowest) {
			lowest = vect[i];
		}
	}
	return lowest;
}

float calcAverage(int vect[]) {
	int sum = 0;

	for (int i = 0; i < LENGTH; i++) {
		sum += vect[i];
	}
	return (float)sum / (float)LENGTH;
}

int search(int n, int vect[]) {
	for (int i = 0; i < LENGTH; i++) {
		if (vect[i] == n) return i;
	}
	return -1;
}

void showMultiplied(int vect[], int n) {
	for (int i = 0; i < LENGTH; i++) {
		printf(" %d ", vect[i] * n);
	}
	printf("\n");
}

int main() {
	int option;

	system("cls");
	printf("\n ==== Choose the size of the vector ==== \n");
	printf(" Enter the length of the vector: ");
	scanf(" %d", &LENGTH);
	int *vect = (int *) malloc(LENGTH * sizeof(int));

	system("cls");
	printf("\n ==== Choose a way to generate the vector ==== \n");
	printf(" 1 Enter values by hand \n");
	printf(" 2 Aleatory vector \n");
	printf(" >> ");
	scanf(" %d", &option);
	
	if (option == 1) {
		for (int i = 0; i < LENGTH; i++) {
			printf(" Type the %do value: ", i+1);
			scanf(" %d", &vect[i]);
		}
	} else if (option == 2) {
		srand(time(NULL));
		for (int i = 0; i < LENGTH; i++) {
			vect[i] = rand() % 50;
		}
	} else {
		printf(" I didn't understand what you typed...");
		return 0;
	}
	
	int num = 0;
	option = 0;
	do {
		system("cls");
		printf(" The vector is: \n");
		show(vect);
		printf(" The highest value is %d \n", calcHighest(vect));
		printf(" The lowest value is %d \n", calcLowest(vect));
		printf(" The average of the vector is %.2f \n", calcAverage(vect));
		
		printf("\n ==== Choose an option ==== \n");
		if (option == 1) {
			printf(" Vector multiplied by %d: \n", num);
			showMultiplied(vect, num);
		} else if (option == 2) {
			printf(" The value %d is in the position %d \n", num, search(num, vect));
		}
		printf(" 1 Multiply by a number \n");
		printf(" 2 Search for a value \n");
		printf(" 3 Exit \n");
		printf(" >> ");
		scanf(" %d", &option);

		if (option == 1 || option == 2) {
			printf(" Which number? \n");
			printf(" >> ");
			scanf(" %d", &num);
		}
	} while(option != 3);

	printf(" See ya! :D");
	return 0;
}
