#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>


int menu(float n1, float n2) //Mostra só o menu
{
    system("cls");
    printf("========== CALCULADORA ==========\n");
    printf(" [%4.2f]    [%4.2f]\n", n1, n2);
    return 0;
}


int menu_opcoes(float n1, float n2, int *op, char *opera, float *r, bool *mr) //Mostra menu com opcoes
{
    system("cls");
    printf("========== CALCULADORA ==========\n");
    if (*mr == true) //Se não for pra mostrar o resultado
        printf(" [%4.2f] %c [%4.2f] = %4.2f \n [1] - Soma \n [2] - Subtracao \n [3] - Multiplicacao \n [4] - Divisao \n [5] - Digitar outros numeros \n [6] - Sair \n => Escolha: ", n1, *opera, n2, *r);
    else
    {
        printf(" [%4.2f]   [%4.2f] \n [1] - Soma \n [2] - Subtracao \n [3] - Multiplicacao \n [4] - Divisao \n [5] - Digitar outros numeros \n [6] - Sair \n => Escolha: ", n1, n2);
    }
    scanf(" %d", op);
    setbuf(stdin, NULL);
    *mr = true;
    return 0;
}


int inserir_numeros(float *n1, float *n2, bool *mr) //Funcao de entrada
{  
    *mr = false; //Apagar resultado até digitar os novos números
    printf(" - Digite o primeiro numero: ");
    scanf(" %f", n1);
    setbuf(stdin, NULL);
    printf(" - Digite o segundo numero: ");
    scanf(" %f", n2);
    setbuf(stdin, NULL);
    return 0;
}


float soma(float n1, float n2)
{
    return n1 + n2;
}


float subtracao(float n1, float n2)
{
    return n1 - n2;
}


float multiplicacao(float n1, float n2)
{
    return n1 * n2;
}


float divisao(float n1, float n2)
{
    if (n1 == 0)
    {
        return 0;
    }
    else
    {
        return n1 / n2;
    }
}


int escolher(float *n1, float *n2, float *r, char *opera, int *op, bool *mr)
{
    switch (*op)
    {
        case 1:
            *r = soma(*n1, *n2);
            *opera = '+';
            break;
        case 2:
            *r = subtracao(*n1, *n2);
            *opera = '-';
            break;
        case 3:
            *r = multiplicacao(*n1, *n2);
            *opera = '*';
            break;
        case 4:
            *r = divisao(*n1, *n2);
            *opera = '/';
            break;
        case 5:
            inserir_numeros(n1, n2, mr);
            break;
        case 6:
            break;
        default:
            printf(" - Nao entendi :/ \n");
            Sleep(1000);
    }
    return 0;
}


int saindo_programa(float n1, float n2, int *op, FILE *val)
{
    char resp[10];
    menu(n1, n2);
    printf(" - Tem certeza? [S/N] ");   
    fgets(resp, 10, stdin); 
    setbuf(stdin, NULL);
    strcpy(resp, strupr(resp));
    if (resp[0] == 'N')    
    {
        *op = 0;
    }
    val = fopen("66num.txt", "w"); //Trocar modo de leitura para escrita
    fprintf(val, "%4.2f %4.2f", n1, n2);
    fclose(val);
    return 0;
}
