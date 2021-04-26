#include <stdio.h>

//#Comando nome_da_constante valor
#define pi2 3.1415 //Pode ser desse jeito

int main()
{
	const double pi = 3.1415; //Tambem pode ser desse jeito
	
	printf("Constante normal: %f \n", pi);
	printf("Constante pre-processador: %f", pi2);
	return 0;
}
