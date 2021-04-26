#include <stdio.h>
#include <stdlib.h>

#define LENGTH 15

void showEven(int arr[]) {
	printf(" Evens: ");
	for (int i = 0; i < LENGTH; i+=2) {
		printf(" %d,", arr[i]);
	}
	printf("\n");
}

void showOdd(int arr[]) {
	printf(" Odds: ");
	for (int i = 1; i < LENGTH; i+=2) {
		printf(" %d,", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[LENGTH];

	for (int i = 0; i < LENGTH; i++) {
		if (i == (LENGTH - 1)) printf(" - Type the last value: ");
		else printf(" - Type the %do value: ", i+1);
		scanf(" %d", &arr[i]);
	}
	
	showEven(arr);
	showOdd(arr);
	return 0;
}
