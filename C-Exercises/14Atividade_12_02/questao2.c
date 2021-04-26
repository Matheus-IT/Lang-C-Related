#include <stdio.h>

void linha1(int length) {
	for (int i = 0; i < length; i++)
		printf("*");
	printf("\n");
}

void linha2(int length) {
	for (int i = 0; i < length; i++)
		printf("=");
	printf("\n");
	
	for (int i = 0; i < length; i++)
		printf("#");
	printf("\n");

}

int main() {
	int n;
	scanf("%d", &n);

	linha1(n);
	linha2(n);
	return 0;
}