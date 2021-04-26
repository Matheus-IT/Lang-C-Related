#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n;
    n = 0;

    do
    {
        printf("Digite um numero inteiro (0 parar): ");
        scanf(" %d", &n);
        (n % 2 == 0) ? printf("Numero par! \n") : printf("Numero impar! \n");
    }while(n != 0);
    return 0;
}
