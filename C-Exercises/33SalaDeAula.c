#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(){
    char nome[50], melhor_A[50];
    float n1, n2, n3, m, melhor_M;

    for (int cont = 0; cont < 3; cont++) //Registra 3 alunos
    {
        printf("\n\
=============================================\n\
=========== ESCOLA JAVALI CANSADO ===========\n\
=============================================\n");

        printf(" - Digite o nome do %do aluno: ", cont+1);
        scanf("%s", &nome);
        strcpy(nome, strupr(nome)); //Converte nome para UPPERCASE e "resalva" em nome
        printf(" - Digite a primeira nota: ");
        scanf("%f", &n1);
        printf(" - Digite a segunda nota: ");
        scanf("%f", &n2);
        printf(" - Digite a ultima nota: ");
        scanf("%f", &n3);
        m = (n1 + n2 + n3)/3; //Cálculo da média

        if (cont == 0) //O primeiro aluno já será o melhor
        {
            strcpy(melhor_A, nome);
            melhor_M = m;
        }
        else if (m > melhor_M)
        {
            strcpy(melhor_A, nome);
            melhor_M = m;
        }
    }
    printf("=============================================\n");
    printf("O melhor aluno foi %s com media %4.2f \n", melhor_A, melhor_M);
    return 0;
}
