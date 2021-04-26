#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
	char num;

	printf(" - Type a number (don't use Enter) \n");
	printf(" - Evens: \n");
	for (int i = 0; i < 10; i++) {
		do {
			num = getche();
			num = num - '0'; // to int
		} while (num == -35);
		if (num % 2 == 0) printf("\n");
		else printf("\b\b\b\b\b"); // backspace
	}
	printf("========= \n");
	return 0;
}
