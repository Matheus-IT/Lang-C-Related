#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a, b, soma;
    a = b = soma = 0;

    system("cls");
    printf("Digite um numero A: ");
    scanf(" %d", &a);
    printf("Digite um numero B: ");
    scanf(" %d", &b);
    if (a < b)
    {
        for (int cont = a+1; cont < b; cont++) //Sem considerar nem A nem B
        {
            soma += cont;
        }
    }
    else
    {
        for (int cont = a-1; cont > b; cont--) //Sem considerar nem A nem B
        {
            soma += cont;
        }  
    }
    printf("A soma de todos os valores entre A e B e %d", soma);
    return 0;
}
