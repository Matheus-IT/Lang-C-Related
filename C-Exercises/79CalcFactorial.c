#include <stdio.h>
#include <stdlib.h>

int calcFactorial(int n) {
	int fact = 1;
	while (n > 1) {
		fact *= n;
		n--;
	}
	return fact;
}

int main() {
	int num = 0;

	printf(" - Enter a number to calculate the factorial: ");
	scanf(" %d", &num);
	printf(" - %d! = %d", num, calcFactorial(num));
	return 0;
}
