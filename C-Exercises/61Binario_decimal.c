#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int bin_para_dec(char bin[])
{
    int result = 0;
    int tam = strlen(bin);

    for (int cont = tam-2, cont2 = 0; cont >= 0; cont--,cont2++)
    {
        if (bin[cont] == '1')
            result += 1 * pow(2, cont2);
    }
    return result;
}


int main()
{
    char binario[256];
    int decimal = 0;

    printf(" - Digite um numero binario: ");
    fgets(binario, 256, stdin);
    decimal = bin_para_dec(binario);
    printf(" - O numero %s em decimal %d\n", binario, decimal);
    return 0;
}
