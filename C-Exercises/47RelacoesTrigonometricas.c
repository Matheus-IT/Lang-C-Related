#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

void cabecalho(int p, int v);
_Bool stringIgual(char s1[], char s2[]);
void sortOpcoes();

int main()
{
    int op, pontos, vidas;
    op = pontos = 0;
    vidas = 3;
    char resp[30];


    do
    {
        system("cls");
        cabecalho(pontos, vidas);
        srand(time(NULL)); //Continuar sorteando numeros
        op =  rand()%9; //Sortear 9 numeros (entre 0 e 8)
        switch (op)
        {
        case 0:
            printf(" - Qual o SENO de 30 graus? (Pode ser por extenso) ");
            fflush(stdin);
            gets(resp);
            strcpy(resp, strupr(resp));
            if (!(strcmp(resp, "UM SOBRE DOIS")) || !(strcmp(resp, "1/2"))) // -> Operador de negação
            {
                printf(" - Resposta correta! \n");
                pontos += 20; //Acrecimo de pontuacao
                printf(" - Voce ganhou 20 pontos! \n");
            }
            else
            {
                printf(" - Resposta incorreta! \n");
                vidas -= 1; //Perde uma vida
                printf(" - Voce perdeu uma vida! :C \n");
            }
            break;
        case 1:
            printf(" - Qual o COSSENO de 30 graus?\n");
            printf(" - [1]Raiz de tres sobre dois\n");
            printf(" - [2]Raiz de dois sobre dois\n");
            printf(" - [3]Raiz de tres sobre tres\n");
            printf(" - [4]Raiz de tres\n");
            printf(" => ");
            fflush(stdin);
            gets(resp);
            if (resp[0] == '1')
            {
                printf(" - Resposta correta! \n");
                pontos += 10;
                printf(" - Voce ganhou 10 pontos! \n");
            }
            else
            {
                printf(" - Resposta incorreta! \n");
                vidas -= 1;
                printf(" - Voce perdeu uma vida! :C \n");
            }
            break;
        case 2:
            printf(" - Qual a TANGENTE de 30 graus?\n");
            printf(" - [1]Raiz de dois sobre dois\n");
            printf(" - [2]Raiz de tres sobre dois\n");
            printf(" - [3]Raiz de tres\n");
            printf(" - [4]Raiz de tres sobre tres\n");
            printf(" => ");
            fflush(stdin);
            gets(resp);
            if (resp[0] == '4')
            {
                printf(" - Resposta correta! \n");
                pontos += 10;
                printf(" - Voce ganhou 10 pontos! \n");
            }
            else
            {
                printf(" - Resposta incorreta! \n");
                vidas -= 1;
                printf(" - Voce perdeu uma vida! :C \n");
            }
            break;
        case 3:
            printf(" - Qual o SENO de 45 graus?\n");
            printf(" - [1]Raiz de tres sobre dois\n");
            printf(" - [2]Raiz de dois sobre dois\n");
            printf(" - [3]Raiz de tres\n");
            printf(" - [4]Raiz de tres sobre tres\n");
            printf(" => ");
            fflush(stdin);
            gets(resp);
            if (resp[0] == '2')
            {
                printf(" - Resposta correta! \n");
                pontos += 10;
                printf(" - Voce ganhou 10 pontos! \n");
            }
            else
            {
                printf(" - Resposta incorreta! \n");
                vidas -= 1;
                printf(" - Voce perdeu uma vida! :C \n");
            }
            break;
        case 4:
            printf(" - Qual o COSSENO de 45 graus?\n");
            printf(" - [1]Raiz de tres sobre dois\n");
            printf(" - [2]Raiz de tres\n");
            printf(" - [3]Raiz de dois sobre dois\n");
            printf(" - [4]Raiz de tres sobre tres\n");
            printf(" => ");
            fflush(stdin);
            gets(resp);
            if (resp[0] == '3')
            {
                printf(" - Resposta correta! \n");
                pontos += 10;
                printf(" - Voce ganhou 10 pontos! \n");
            }
            else
            {
                printf(" - Resposta incorreta! \n");
                vidas -= 1;
                printf(" - Voce perdeu uma vida! :C \n");
            }
            break;
        case 5:
            printf(" - Qual a TANGENTE de 45 graus? (Pode ser por extenso) ");
            fflush(stdin);
            gets(resp);
            strcpy(resp, strupr(resp));
            if (!(strcmp(resp, "UM")) || !(strcmp(resp, "1")))
            {
                printf(" - Resposta correta! \n");
                pontos += 20;
                printf(" - Voce ganhou 20 pontos! \n");
            }
            else
            {
                printf(" - Resposta incorreta! \n");
                vidas -= 1;
                printf(" - Voce perdeu uma vida! :C \n");
            }
            break;
        case 6:
            printf(" - Qual o SENO de 60 graus?\n");
            printf(" - [1]Raiz de tres sobre dois\n");
            printf(" - [2]Raiz de tres\n");
            printf(" - [3]Raiz de dois sobre dois\n");
            printf(" - [4]Raiz de tres sobre tres\n");
            printf(" => ");
            fflush(stdin);
            gets(resp);
            if (resp[0] == '1')
            {
                printf(" - Resposta correta! \n");
                pontos += 10;
                printf(" - Voce ganhou 10 pontos! \n");
            }
            else
            {
                printf(" - Resposta incorreta! \n");
                vidas -= 1;
                printf(" - Voce perdeu uma vida! :C \n");
            }
            break;
        case 7:
            printf(" - Qual o COSSENO de 60 graus? (Pode ser por extenso) ");
            fflush(stdin);
            gets(resp);
            strcpy(resp, strupr(resp));
            if (!(strcmp(resp, "UM SOBRE DOIS")) || !(strcmp(resp, "1/2")))
            {
                printf(" - Resposta correta! \n");
                pontos += 20;
                printf(" - Voce ganhou 20 pontos! \n");
            }
            else
            {
                printf(" - Resposta incorreta! \n");
                vidas -= 1;
                printf(" - Voce perdeu uma vida! :C \n");
            }
            break;
        case 8:
            printf(" - Qual a TANGENTE de 60 graus?\n");
            printf(" - [1]Raiz de tres sobre dois\n");
            printf(" - [2]Raiz de tres sobre tres\n");
            printf(" - [3]Raiz de dois sobre dois\n");
            printf(" - [4]Raiz de tres\n");
            printf(" => ");
            fflush(stdin);
            gets(resp);
            if (resp[0] == '4')
            {
                printf(" - Resposta correta! \n");
                pontos += 10;
                printf(" - Voce ganhou 10 pontos! \n");
            }
            else
            {
                printf(" - Resposta incorreta! \n");
                vidas -= 1;
                printf(" - Voce perdeu uma vida! :C \n");
            }
            break;
        default:
            break;
        }
        Sleep(2000);
    } while (vidas > 0);
    system("cls");
    cabecalho(pontos, vidas);
    printf(" -         GAME OVER        - \n");
    printf(" - Voce fez %d pontos       - \n", pontos);
    
    return 0;
}


void cabecalho(int p, int v)
{
    printf("\
==============================\n\
 - Relacoes Trigonometricas - \n\
==============================\n\
Pontos %d \n\
Vidas  %d \n", p, v);
}


_Bool stringIgual(char s1[], char s2[])
{
    int cont = 0;

    do
    {
        if (s1[cont] != s2[cont])
        {
            return 0;
        }
        cont++;
    } while((s1[cont] == s2[cont]) && (s1[cont] != '\0') && (s2[cont] != '\0'));
    return 1;
}
