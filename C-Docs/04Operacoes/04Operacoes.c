#include <stdio.h>

int main(){
	int a, b, s, multi, sub, res;
	float div;
	a = 8;
	b = 4;
	s = a + b; //Operação de soma
	sub = a - b; //Operação de subtração
	multi = a * b; //Operação de multiplicação
	div = a / b; //Operação de divisão
	res = a % b; //Resto da divisão
	printf("Soma e : %d \n", s );
	printf("Multiplicacao e : %d \n", multi);
	printf("Subtracao e : %d \n", sub);
	printf("Divisao e : %f \n", div);
	printf("O resto da divisao: %d \n", res);
	return 0;
}
