#include <stdio.h>

int factorial(int n) {
	if (n == 1)
		return 1;
	return n * factorial(n-1);
}

int arranjos(int n, int p) {
	return factorial(n) / factorial(n - p);
}

int combinacoes(int n, int p) {
	return factorial(n) / (factorial(p) * factorial(n - p));
}

int main() {
	int n;
	scanf("%d", &n);

	int p;
	scanf("%d", &p);

	printf("Arranjos %d\n", arranjos(n, p));
	printf("Combinacoes %d\n", combinacoes(n, p));
	return 0;
}