#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int n, totImpar, menor, maior, cont;
    n = totImpar = menor = maior = cont = 0;
    char resp[] = "";

    do
    {
        cont ++;
        system("cls");
        printf(" - Digite um numero qualquer: ");
        scanf(" %d", &n);
        if (n % 2 == 1)
        {
            totImpar += n;
        }
        if (cont == 1)
        {
            maior = n;
            menor = n;
        }
        if (n > maior)
        {
            maior = n;
        }
        if (n < menor)
        {
            menor = n;
        }
        printf(" - Quer continuar? [S/N] ");
        scanf(" %s", &resp);
        strcpy(resp, strupr(resp)); //Colocar as letras maiusculas
    } while (resp[0] != 'N');
    printf(" - A soma dos numeros impares e igual a %d \n" ,totImpar);
    printf(" - O maior numero foi %d e o menor numero foi %d \n" ,maior, menor);
    return 0;
}
