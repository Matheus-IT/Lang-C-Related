#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../utils/vectors.c"


#define MAX 15


int main() {
	srand(time(NULL));

	int nums[MAX];
 
	for (int i = 0; i < MAX; i++) {
		nums[i] = rand() % 10;
	}

	puts("\nVector:");
	printVect(nums, MAX);

	puts("\nMatrix:");
	for (int i = 0, c = 0; i < MAX; i++) {
		if (c == 5) {
			c = 0;
			printf("\n");
		}
		c++;
		printf("%d ", nums[i]);
	}
	printf("\n");
	return 0;
}