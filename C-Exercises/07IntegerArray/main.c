#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 20

void printVect(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");
}

int main() {
	int nums1[LENGTH];
	char fileName[] = ".\\numeros.txt";

	FILE *db = fopen(fileName, "w+");

	printf(" - Digite %d numeros para grava-los no arquivo \n", LENGTH);
	for (int i = 0; i < LENGTH; i++) {
		printf("Numero %d: ", i+1);
		scanf(" %d", &nums1[i]);

		fprintf(db, "%d\n", nums1[i]);
	}

	int nums2[LENGTH];
	int i = 0;

	rewind(db);

	char ch;
	while(!feof(db)) {
		ch = fgetc(db);
		if (ch != ' ' && ch != '\n')
			nums2[i++] = atoi(&ch);
	}

	printf("\nVetor A = ");
	printVect(nums1, LENGTH);

	printf("\nVetor B = ");
	printVect(nums2, LENGTH);

	fclose(db);
	return 0;
}
