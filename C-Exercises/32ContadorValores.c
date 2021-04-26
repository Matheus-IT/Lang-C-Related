#include <stdio.h>
#include <stdlib.h>


int main(){
	int val, maior, menor;

	printf("\n\
=========================================================\n\
=============== CONTADOR DE MAIOR E MENOR ===============\n\
=========================================================\n");
	for (int i = 0; i < 5; i++)
	{
		printf(" - Digite o %do valor: ", i+1);
		scanf("%d", &val);
		if (i == 0) //O primeiro valor será o maior e o menor
		{
			maior = val;
			menor = val;
		}
		else if (val > maior) //Conferir se o valor atual é o maior
		{
			maior = val;
		}
		else if (val < menor) //Conferir se o valor atual é o menor
		{
			menor = val;
		}
	}
	printf(" => O maior valor e %d e o menor valor e %d \n", maior, menor);
	return 0;
}
