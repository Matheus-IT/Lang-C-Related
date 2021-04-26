#include <stdio.h>
#include <stdlib.h>


int main(){
	//Operações matemáticas
	int num1 = 15;
	int num2 = 20;

	int soma = num1 + num2;
	printf("O resultado da soma é: %i \n", soma);

	int subt = num2 - num1;
	printf("O resultado da subtração é: %i \n", subt);

	int multi = num1 * num2;
	printf("O resultado da multiplicação é: %i \n", multi);

	int div = num2/3; //Na divisão de inteiros o C ignora as casas decimais
	printf("O resultado da divisão é: %i \n", div);

	return 0;
}
