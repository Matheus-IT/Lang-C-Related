#include <stdio.h>
#include <stdlib.h>

float calcExpression(int n1, int n2, char op) {
	switch (op) {
		case '+':
			return n1 + n2;
			break;
		case '-':
			return n1 - n2;
			break;
		case '*':
			return n1 * n2;
			break;
		case '/':
			if (n2 == 0) return 0;
			else return (float)n1 / (float)n2;
			break;
		default:
			break;
	}
}

int main() {
	int n1, n2;
	char op;
	
	printf(" - Enter an expression (ex: 5 + 2): ");
	scanf("%d %c %d", &n1, &op, &n2);
	printf("%d %c %d = %.2f \n", n1, op, n2, calcExpression(n1, n2, op));
	return 0;
}
