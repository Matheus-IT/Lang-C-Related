#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
    typedef struct
    {
        char nome[50];
        int idade;
        float media;
    }aluno;

    aluno *alunos;
    int qtd = 0;
    printf(" - Quantos alunos cadastrar? ");
    scanf(" %d", &qtd);
    alunos = (aluno *)(calloc(qtd, sizeof(aluno)));
    char n[50];
    for (int cont = 0; cont < qtd; cont++)
    {   
        n[0] = '\0';
        printf(" %d Aluno \n", cont+1);
        printf(" Digite o nome: ");
        setbuf(stdin, NULL);
        fgets(n, 50, stdin);
        strcpy(alunos[cont].nome, n);
        printf(" Digite a idade: ");
        scanf(" %d", &alunos[cont].idade);
        printf(" Digite a media: ");
        scanf(" %f", &alunos[cont].media);
    }
    for (int cont = 0; cont < qtd; cont++)
    {
        printf(" Nome: %s", alunos[cont].nome);
        printf(" Idade: %d \n", alunos[cont].idade);
        printf(" Media: %4.2f \n\n", alunos[cont].media);
    }
    char decisao = 'N';
    printf(" - Cadastra mais um? [S/N] ");
    scanf(" %c", &decisao);
    decisao = toupper(decisao);
    if (decisao == 'S')
    {
        //Alocar espaço pra mais um aluno
        alunos = (aluno *)(realloc(alunos, (qtd+1)*sizeof(aluno)));
        n[0] = '\0';
        printf(" %d Aluno \n", qtd+1);
        printf(" Digite o nome: ");
        setbuf(stdin, NULL);
        fgets(n, 50, stdin);
        strcpy(alunos[qtd].nome, n);
        printf(" Digite a idade: ");
        scanf(" %d", &alunos[qtd].idade);
        printf(" Digite a media: ");
        scanf(" %f", &alunos[qtd].media);
        //Mostrar informacoes do novo aluno
        printf(" Nome: %s", alunos[qtd].nome);
        printf(" Idade: %d \n", alunos[qtd].idade);
        printf(" Media: %4.2f \n\n", alunos[qtd].media);
    }
    return 0;
}
