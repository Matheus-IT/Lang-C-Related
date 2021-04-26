#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main()
{
    char exadecimal[256];
    int decimal = 0;

    printf(" - Digite um numero exadecimal: ");
    fgets(exadecimal, 256, stdin);
    for (int cont = strlen(exadecimal)-2, cont2 = 0; cont >= 0; cont--, cont2++)
    {
        switch (exadecimal[cont])
        {
            case 'A':
            case 'a':
                decimal += 10 * pow(16, cont2);
                break;
            case 'B':
            case 'b':
                decimal += 11 * pow(16, cont2);
                break;
            case 'C':
            case 'c':
                decimal += 12 * pow(16, cont2);
                break;
            case 'D':
            case 'd':
                decimal += 13 * pow(16, cont2);
                break;
            case 'E':
            case 'e':
                decimal += 14 * pow(16, cont2);
                break;
            case 'F':
            case 'f':
                decimal += 15 * pow(16, cont2);
                break;
            default:
                decimal += (exadecimal[cont]-'0') * pow(16, cont2);
        }
    }
    printf(" - Decimal %d", decimal);
    return 0;
}
