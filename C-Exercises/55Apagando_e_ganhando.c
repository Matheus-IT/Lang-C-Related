#include <stdio.h>
#include <stdlib.h>


int preencher_lousa(int l[], int tam)
{
    for (int cont = 0; cont < tam; cont++)
    {
        printf(" - Digite o %d numero: ", cont+1);
        scanf(" %d", &l[cont]);
    }
}


int maior_premio(int l[], int qtd, int apagar)
{
    int menor = 0;
    int pos = 0;
    for (int i = 0; i < apagar; i++)
    {
        for (int j = 0; j < qtd; j++)
        {
            if (j == 0)
            {
                menor = l[j];
                pos = j;
            }
            else if (l[j] < menor)
            {
                menor = l[j];
                pos = j;
            }
        }
        for (int cont = pos; cont < qtd; cont++)
        {
            l[cont] = l[cont+1];
        }
        qtd--;
    }
    for (int cont = 0; cont < qtd; cont++)
    {
        printf(" %d", l[cont]);
    }
    return 0;
}


int main()
{   
    int n, d;
    n = d = 0;

    
    printf(" - Quantos numeros o apresentador escreveu na lousa? ");
    scanf(" %d", &n);
    while ((n <= 1) || (n > 100000))
    {
        printf(" - Entrada invalida! Quantos numeros o apresentador escreveu na lousa? ");
        scanf(" %d", &n);
    }
    int lousa[n];
    preencher_lousa(lousa, n);
    printf(" - Quantos numeros voce tem que apagar? ");
    scanf(" %d", &d);
    while ((d < 1) || (d >= n))
    {
        printf(" - Entrada invalida! Quantos numeros voce tem que apagar? ");
        scanf(" %d", &d);
    }
    maior_premio(lousa, n, d);
    return 0;
}
