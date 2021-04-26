#include <stdio.h>

int main() {
	int vect[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) printf("%d \t", vect[i]);
		else printf("%d \n", vect[i]);
	}
}
