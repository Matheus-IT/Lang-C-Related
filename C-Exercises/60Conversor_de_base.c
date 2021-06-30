#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int tam = 0; //Variavel global

int * conv_decimal(int n)
{
    int *resto = NULL;
    tam = 0;

    int nb = n; //Fazer backup do valor de n
    while (nb > 0)
    {
        nb /= 2;
        tam++; //Contar quantos restos terão
    }
    resto = (int *)(malloc(tam * sizeof(int))); //Vetor dinamico com restos
    nb = n;
    int c = tam-1;
    while (nb > 0)
    {
        resto[c] = nb % 2;
        c--;
        nb /= 2;
    }
    return resto;
}


int * conv_octal(int n)
{
    int *resto = NULL;
    tam = 0;

    int nb = n; //Fazer backup do valor de n
    while (nb > 0)
    {
        nb /= 8;
        tam++; //Contar quantos restos terão
    }
    resto = (int *)(malloc(tam * sizeof(int))); //Vetor dinamico com restos
    nb = n;
    int c = tam-1;
    while (nb > 0)
    {
        resto[c] = nb % 8;
        c--;
        nb /= 8;
    }
    return resto;
}


char * conv_exadecimal(int n)
{
    char *resto = NULL;
    tam = 0;

    int nb = n; //Fazer backup do valor de n
    while (nb > 0)
    {
        nb /= 16;
        tam++; //Contar quantos restos terão
    }
    resto = (char *)(malloc(tam * sizeof(char))); //Vetor dinamico com restos
    nb = n;
    int c = tam-1;
    while (nb > 0)
    {
        switch (nb % 16)
        {
            case 10:
                resto[c] = 'A';
                break;
            case 11:
                resto[c] = 'B';
                break;
            case 12:
                resto[c] = 'C';
                break;
            case 13:
                resto[c] = 'D';
                break;
            case 14:
                resto[c] = 'E';
                break;
            case 15:
                resto[c] = 'F';
                break;
            default:
                resto[c] = (nb % 16)+'0';
        }
        c--;
        nb /= 16;
    }
    return resto;
}


int mostra(int *v)
{
    for (int cont = 0; cont < tam; cont++)
    {
        printf(" %d ", v[cont]);
    }
    printf("\n");
    return 0;
}


int mostra_exa(char *v)
{
    for (int cont = 0; cont < tam; cont++)
    {
        printf(" %c ", v[cont]);
    }
    return 0;
}


int main()
{
    int num = 0;
    int *decimal = NULL;
    int *octal = NULL;
    char *exadecimal = NULL;

    printf(" - Digite um numero inteiro: ");
    scanf(" %d", &num);
    decimal = conv_decimal(num);
    printf(" - %d em Decimal: \n", num);
    mostra(decimal);
    // octal = conv_octal(num);
    // printf("\n - %d em Octal: \n", num);
    // mostra(octal);
    // exadecimal = conv_exadecimal(num);
    // printf("\n - %d em Exadecimal: \n", num);
    // mostra_exa(exadecimal);
    return 0;
}
