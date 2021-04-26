#include <stdio.h>
#include <stdlib.h>


/*DECLARACAO DE FUNCAO*/
int quadrado(int n);


void main()
{
    int num, resultado;
    
    system("cls");
    printf("Digite um numero para calcular o quadrado: ");
    scanf(" %i", &num);
    resultado = quadrado(num);
    printf("Resultado: %i \n", resultado);
}


/*DEFINICAO DE FUNCAO*/
int quadrado(int n)
{
    int res = n * n;
    return res;
}
