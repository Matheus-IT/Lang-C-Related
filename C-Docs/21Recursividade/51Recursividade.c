#include <stdio.h>
#include <stdlib.h>


int calc_fat(int n) //Declaracao e definicao da funcao
{
    if (n == 1) //Base para o calculo do fatorial
    {
        return 1;
    }
    else
    {
        return (n * (calc_fat(n - 1))); //Recursao
    }
}


int main()
{
    int num = 0, fat = 0;

    printf(" - Digite um numero para calcular o fatorial: ");
    scanf(" %d", &num);
    fat = calc_fat(num);
    printf(" - Fatorial de %d e igual a %d", num, fat);
    return 0;
}
