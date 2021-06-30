#include <stdio.h>


int doSum(int a, int b, int c, int d) {
	int smaller = a;

	if (b < smaller)
		smaller = b;
	if (c < smaller)
		smaller = c;
	if (d < smaller)
		smaller = d;
	
	return (a + b + c + d) - smaller;
}


int main() {
	int n1, n2, n3, n4, sum;

	printf("\nType 4 distinct numbers: ");
	scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

	sum = doSum(n1, n2, n3, n4);

	printf("\nResult: %d\n", sum);
	return 0;
}