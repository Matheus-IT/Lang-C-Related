#include <stdio.h>
#include <stdlib.h>


int mostra_Res(int *r)
{
    int tam = sizeof(r);
    for (int cont = tam; cont >= 0; cont--)
    {
        printf(" %d", r[cont]);
    }
    return 0;
}


int decimal_Binario(int n)
{
    int cont, cont2;
    cont = cont2 = 0;
    int *res = NULL;

    for (int numB = n; numB > 0; numB /= 2) //Avaliar quantos espacos vai precisar
    {
        cont++;
    }
    res = (int *)(malloc(cont * sizeof(int))); //Vetor para armazenar os restos das divisoes
    for (int numB = n; numB > 0; numB /= 2)
    {
        res[cont2] = numB % 2;
        cont2++;
    }
    mostra_Res(res);
    return 0;
}


int main()
{
    int num = 0;

    printf(" - Digite um numero:");
    scanf(" %d", &num);
    decimal_Binario(num);
    return 0;
}
