#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n, cont_div;
    n = cont_div = 0;

    system("cls");
    printf("Digite um numero inteiro: ");
    scanf(" %d", &n);
    //Numeros sao divisiveis da metade pra baixo
    for (int i = n/2; i >= 1; i--)
    {
        if (n % i == 0)
        {
            cont_div++;
        }
    }
    if (cont_div == 1)
    {
        printf("O valor digitado %d e primo! \n", n);
    }
    else
    {
        printf("O valor digitado %d nao e primo! \n", n);
    }
    return 0;
}
