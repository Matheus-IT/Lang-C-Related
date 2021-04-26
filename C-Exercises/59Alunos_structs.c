#include <stdio.h>
#include <stdlib.h>

const int max = 3;

int limpar_buffer()
{
    char ch;
    while ((ch = getchar())!= '\n' && ch != EOF);
    return 0;
}


int main()
{
    struct aluno
    {
        char nome[50];
        float nota;
    };
    struct aluno alunos[max]; //Variavel tipo struct aluno
    for (int cont = 0; cont < max; cont++)
    {
        printf(" - Digite o %do nome: ", cont+1);
        if (cont != 0)limpar_buffer();
        fgets(alunos[cont].nome, 50, stdin);
        printf(" - Digite a %do nota: ", cont+1);
        scanf(" %f", &alunos[cont].nota);
    }
    for (int cont = 0; cont < max; cont++)
    {
        printf("Aluno: %sNota: %4.2f\n", alunos[cont].nome, alunos[cont].nota);
    }
    return 0;
}
