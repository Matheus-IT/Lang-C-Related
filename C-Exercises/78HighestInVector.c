#include <stdio.h>
#include <stdlib.h>

/* Matheus Costa =D */

int main() {
	int num = 0, highest = 0;
	
	printf(" - Type any int number: ");
	scanf(" %d", &num);
	if (num > highest) highest = num;
	
	printf(" - Type any int number: ");
	scanf(" %d", &num);
	if (num > highest) highest = num;
	
	printf(" - Type any int number: ");
	scanf(" %d", &num);
	if (num > highest) highest = num;
	
	printf(" - Type any int number: ");
	scanf(" %d", &num);
	if (num > highest) highest = num;
	
	printf(" - Type any int number: ");
	scanf(" %d", &num);
	if (num > highest) highest = num;
	
	printf(" - The highest is %d \n", highest);
	return 0;
}
