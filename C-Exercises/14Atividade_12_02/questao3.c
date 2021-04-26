#include <stdio.h>

int numeroEhCapicua(int n) {
	int unidade = n % 10;
	int dezena = n / 10 % 10;
	int centena = n / 100 % 10;
	int milhar = n / 1000 % 10;

	if (unidade == milhar && dezena == centena)
		return 1;
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);

	printf("%d", numeroEhCapicua(n));
	return 0;
}