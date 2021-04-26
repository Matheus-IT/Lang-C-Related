#include <stdio.h>
#include <stdlib.h>


int main()
{
    /*
    Faca um programa que leia uma quantidade qualquer de 
    numeros armazenando-os namemoria e pare a leitura 
    quando o usuario entrar um numero negativo. Em seguida,
    imprima o vetor lido. Use a funcao REALLOC
    */
    int *numeros = (int *)malloc(sizeof(int));

    int cont = 0;
    int num = 0;
    while (num >= 0)
    {
        printf(" - Digite um valor: ");
        scanf(" %d", &num);
        numeros[cont] = num;
        cont++;
        numeros = realloc(numeros, sizeof(numeros)+sizeof(int)); //Alocar memoria pra mais um
    }
    for (int cont = 0; cont < sizeof(numeros); cont++)
    {
        printf(" %d ", numeros[cont]);
    }
    printf("\n");
    free(numeros);
    return 0;
}
