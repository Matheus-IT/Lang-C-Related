#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n, cont;
    n = 0;
    cont = 1;

    printf("Digite um numero inteiro: ");
    scanf(" %d", &n);
    do
    {
        printf("%d \n", cont);
        cont += 2;
    }while(cont < n);
    return 0;
}
