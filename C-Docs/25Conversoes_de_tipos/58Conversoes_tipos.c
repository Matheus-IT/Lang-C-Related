#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char operacao(char ex[])
{
    for (int cont = 0; cont < strlen(ex); cont++)
    {
        if ((ex[cont] == '+') || (ex[cont] == '-') || (ex[cont] == '*') || (ex[cont] == '/'))
        {
            return ex[cont];
        }
    }
    return 'f';
}


float operacoes(char ex[]) //Recebe a expressao
{
    /*
        FUNCOES ESPECIFICAS PARA CONVERSOES EM C
        atof() Conversão de string em float
        atoi() Conversão de string to int //Evitar usar, em vez disso -> caractere_char - '0'
        atol() Conversão de string to long
        itoa(num, string, 10//binary) Conversão de int to string
        ltoa() Conversão de long to string
    */
    float res;
    switch (operacao(ex))
    {
    case '+':
        res = atoi(&ex[0]) + atoi(&ex[2]); //atoi() -> Converte String para inteiro
        break;
    case '-':
        res = atoi(&ex[0]) - atoi(&ex[2]);
        break;
    case '*':
        res = atoi(&ex[0]) * atoi(&ex[2]);
        break;
    case '/':
        res = atof(&ex[0]) / atof(&ex[2]); //atof() -> Converte String para float
        break;
    case 'f': //Caso a expressao seja invalida
        res = 0;
        break;
    }
    return res;
}


int main()
{
    char exp[100];
    float r = 0;

    system("cls");
    printf("=============== Programa leitor inteligente ===============\n");
    printf(" - Digite uma expressao (<valor 1> <operador> <valor 2>): ");
    scanf(" %s", &exp);
    r = operacoes(exp); //Mandar a expressao para a funcao operacoes e atribui a r
    if (r == 0)
    {
        printf(" - Operacao invalida");
    }
    else
    {
        for (int cont = 0; cont < strlen(exp); cont++)
        {
            printf("%c", exp[cont]);
        }
        printf(" = %4.2f", r);
    }
    return 0;
}
