#include <stdio.h>
#include <stdlib.h>


void troca(int num1, int num2) //Parametros passados por valor
{
    int aux = num1;
    num1 = num2;
    num2 = aux;
}


void troca2(int *num1, int *num2) //Parametros passados por referencia
{
    int aux = *num1;
    *num1 = *num2;
    *num2 = aux;
}


int main()
{
    int n1, n2;

    system("cls");
    printf("Digite um numero: ");
    scanf(" %d", &n1);
    printf("Digite outro numero: ");
    scanf(" %d", &n2);
    troca(n1, n2); //Passados por valor
    printf("Parametros passados por valor nao mudam o resultado:\n");
    printf("n1 = %d\n", n1);
    printf("n2 = %d\n", n2);
    troca2(&n1, &n2); //Passados por referencia
    printf("Parametros passados por referencia MUDAM n1 e n2\n");
    printf("n1 = %d\n", n1);
    printf("n2 = %d\n", n2);
    return 0;
}
