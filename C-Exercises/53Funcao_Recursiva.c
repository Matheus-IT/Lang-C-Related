#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


int fatorial(int fat) //Funcao recursiva para calculo de fatorial
{
    if (fat == 1)
    {
        printf(" 1 ");
        Sleep(500);
        printf("= ");
        Sleep(500);
        return 1;
    }
    else
    {
        printf(" %d", fat);
        Sleep(500);
        printf(" x");
        Sleep(500);
        return fat * fatorial(fat - 1);
    }
}


int main()
{
    int n, r;

    printf(" - Digite um numero: ");
    scanf(" %d", &n);
    printf(" - O fatorial de %d e igual a", n);
    r = fatorial(n);
    printf("%d\n", r);
    return 0;
}
