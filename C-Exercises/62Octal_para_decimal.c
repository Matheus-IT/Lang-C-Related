#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{
    char num[256];
    int decimal = 0;

    printf(" - Digite um numero em octal: ");
    fgets(num, 256, stdin);
    for (int cont = strlen(num)-2, cont2 = 0; cont >= 0; cont--, cont2++)
    {
        decimal += (num[cont]-'0') * pow(8, cont2);
    }
    printf(" - Decimal %d", decimal);
    return 0;
}
