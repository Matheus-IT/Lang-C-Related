#include <stdio.h>
#include <stdlib.h>


unsigned * convertToBinary(unsigned n, int *lengthOfResult) {
	// First of all, let's see the length of the future rest vector
	unsigned nBackup = n;
	while (n > 0) {
		n /= 2;
		(*lengthOfResult)++;
	}

	// Now we can allocate memory and fill up the result vector
	int *result = (int *) malloc(*lengthOfResult * sizeof(int));

	// The vector is gonna hold the rests backwards, making a binary
	int i = (*lengthOfResult)-1;
	n = nBackup;
	while (n > 0) {
		result[i--] = n % 2;
		n /= 2;
	}
	return result;
}


void printVector(int *vect, unsigned length) {
	printf("[");
	for (int i = 0; i < length; i++) {
		printf("%d", vect[i]);

		if (i != length-1)
			printf(",");
	}
	printf("]\n");
}


int main() {
	unsigned n;
	printf("Type a number: ");
	scanf("%d", &n);

	unsigned lengthOfNBinary = 0;
	unsigned *nBinary = convertToBinary(n, &lengthOfNBinary);

	printf("%d to binary: ", n);
	printVector(nBinary, lengthOfNBinary);
	return 0;
}