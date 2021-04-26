#include <stdio.h>

void desenhaQuadro(char character, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			printf("%c", character);
		printf("\n");
	}
}

int main() {
	char symbol = 'x';
	unsigned size = 5;
	desenhaQuadro(symbol, size);
	return 0;
}