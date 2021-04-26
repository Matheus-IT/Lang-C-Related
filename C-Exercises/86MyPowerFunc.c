#include <stdio.h>
#include <stdlib.h>

int myPower(int base, int exponent) {
	if (exponent == 0) {
		return 1;
	} else if (exponent == 1) {
		return base;
	} else {
		return base * myPower(base, exponent - 1);
	}
}

int main() {
	int base = 0, exponent = 0;

	printf(" - Type an expression like 3 ** 4 \n");
	printf(" >> ");
	scanf(" %d ** %d", &base, &exponent);
	printf(" %d ** %d = %d \n", base, exponent, myPower(base, exponent));
	return 0;
}
