#include <stdio.h>
#include <stdlib.h>

#define LENGTH 5

void printVect(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		printf(" %d", arr[i]);
	}
	printf("\n");
}

int main() {
	char fileName[] = ".\\numeros.txt";
	FILE *db = fopen(fileName, "r");
	int nums2[LENGTH];
	int i = 0;
	char ch;

	while(ch != EOF) {
		ch = fgetc(db);
		printf("%c", ch);

		if (ch != '\n')
			nums2[i++] = ch;
	}

	printf("\nVetor B = ");
	printVect(nums2, LENGTH);

	fclose(db);
	return 0;
}
