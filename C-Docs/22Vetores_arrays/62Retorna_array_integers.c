#include <stdio.h>
#include <stdlib.h>

const int qtd = 5;


int * pares() //This function are returning a pointer
{
    static int n[5]; //This guy has to be a static
    int pares = 0;
    for (int cont = 0; cont < qtd; cont++) //5 even numbers
    {
        n[cont] = pares += 2;
    }
    return n;
}


int main()
{
    int *numeros;

    numeros = pares(); //This function returns an array of integers
    for (int cont = 0; cont < qtd; cont++)
    {
        printf(" %d", numeros[cont]);
    }
    return 0;
}
