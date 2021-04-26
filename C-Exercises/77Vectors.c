#include <stdio.h>
#include <stdlib.h>

void showVect(int vect[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%d ", vect[i]);
	}
	printf("\n");
}

int * concatVect(int vect1[], int length1, int vect2[], int length2) {
	int length3 = length1 + length2;
	int *vect3 = (int *) malloc(length3 * sizeof(int));

	int i = 0;
	for (int j = 0; j < length1; j++) {
		vect3[i] = vect1[j];
		i++;
	}

	for (int j = 0; j < length2; j++) {
		vect3[i] = vect2[j];
		i++;
	}

	return vect3;
}

int main() {
	int vect1[] = {1, 2, 3};
	int length1 = sizeof(vect1) / sizeof(vect1[0]);

	int vect2[] = {4, 5, 6, 7};
	int length2 = sizeof(vect2) / sizeof(vect2[0]);

	int *vectRes = NULL;
	int lengthRes = length1 + length2;

	// using static vectors
	vectRes = concatVect(vect1, length1, vect2, length2);
	printf("VectRes: ");
	showVect(vectRes, lengthRes);

	// using dinamic vectors
	int length3 = lengthRes + length1;
	int *vect3 = (int *) malloc(length3 * sizeof(int));
	
	vect3 = concatVect(vectRes, lengthRes, vect1, length1);
	printf("Vect3: ");
	showVect(vect3, length3);

	int length4 = lengthRes + length2;
	int *vect4 = (int *) malloc(length4 * sizeof(int));

	vect4 = concatVect(vectRes, lengthRes, vect2, length2);
	printf("Vect4: ");
	showVect(vect4, length4);

	free(vectRes);
	free(vect3);
	free(vect4);
	return 0;
}
