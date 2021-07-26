#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	char name[64];

	printf("Type your name: ");
	scanf(" %[^\n]", name);

	printf("%s\n", name);
	return 0;
}