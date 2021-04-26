#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


const int max = 5; //Qtd de pessoas
const int tam = 50;


int preencher(char p[max][tam])
{
    for (int cont = 0; cont < max; cont++)
    {
        printf(" - Digite o nome da %do pessoa: ", cont+1);
        fgets(p[cont], tam, stdin);
    }
    return 0;
}


char procurar(char p[max][tam])
{
    char nome[tam];
    printf(" - Procurar quem: ");
    fgets(nome, tam, stdin);
    for (int cont = 0; cont < max; cont++)
    {
        if (!strcmp(p[cont], nome))
        {
            return 'V';
        }
        else if (cont == max-1)
        {
            return 'F';
        }
    }
}


int main()
{   
    system("cls");
    char pessoas[max][tam];
    char resp = 'S';
    preencher(pessoas);
    while (resp == 'S')
    {
        if (procurar(pessoas) == 'V')
        {
            printf(" - Achei! :)\n");
        }
        else
        {
            printf(" - Nao achei! :(\n");
        }
        printf(" - Quer continuar[S/N]? ");
        scanf(" %c", &resp);
        resp = toupper(resp);
    }
    printf(" - Tchau! :D");
    return 0;
}
