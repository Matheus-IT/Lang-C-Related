#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


//Declaracao de funcoes
void cabecalho();
void operacoes(float n1, float n2);


int main()
{   
    char resp[6] = "";
    
    do
    {
        float v1, v2;
        v1 = v2 = 0;

        cabecalho();
        printf("Digite o primeiro valor: ");
        scanf(" %f", &v1);
        printf("Digite o segundo valor: ");
        scanf(" %f", &v2);

        cabecalho();
        operacoes(v1, v2);

        /*SAINDO DO PROGRAMA*/
        printf("Digitar outros numeros? [S/N] ");
        fflush(stdin); //Limpando o buffer do teclado
        gets(resp);
        strcpy(resp, strupr(resp));
        while ((resp[0] != 'S') && (resp[0] != 'N')) //Erros de digitacao
        {
            printf("Opcao invalida! Digitar outros valores? [S/N] ");
            gets(resp);
            strcpy(resp, strupr(resp));
        }
    }while (resp[0] == 'S');
    return 0;
}


//DEFINICAO DE FUNCOES
void cabecalho()
{
    system("cls");
    printf("\
==========================================\n\
========== CALCULADORA DO WHILE ==========\n\
==========================================\n");
}


void operacoes(float n1, float n2) //Funcao nao tem retorno
{
    printf("[%4.2f] - [%4.2f] \n", n1, n2);
    Sleep(500);
    printf("Soma: %4.2f \n", n1 + n2);
    Sleep(500);
    printf("Subtracao: %4.2f \n", n1 - n2);
    Sleep(500);
    printf("Multiplicacao: %4.2f \n", n1 * n2);
    Sleep(500);
    if (n2 != 0) //Caso da divisao por 0
    {
        printf("Divisao: %4.2f \n", n1 / n2);
    }else
    {
        printf("Divisao Indeterminada \n");
    }
}
