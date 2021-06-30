#include <stdio.h>


int decompose(int num) {
	/* This function decompose a number and returns
	   how many digits it has:
		num = num / 10; // 100000
		num = num / 10; // 10000
		num = num / 10; // 1000
		num = num / 10; // 100
		num = num / 10; // 10
		num = num / 10; // 1
		num = num / 10; // 0
	*/
	int i;
	for (i = 0; num > 0; i++) {
		num = num / 10;
	}
	return i;
}


int main() {
	long n = 1987645; 
	printf("Result: %i\n", decompose(n));
	return 0;
}