#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "76Funcoes.c" //Importando os codigos do arquivo "76Funcoes.c"


int main()
{
    int n1, n2, op;
    n1 = n2 = op = 0;

    printf(" - Digite o primeiro numero: ");
    scanf(" %d", &n1);
    printf(" - Digite o segundo numero: ");
    scanf(" %d", &n2);
    printf(" - MENU DE OPCOES - \n\t1 - Soma \n\t2 - Subtracao \n\t3 - Multiplicacao \n\t4 - Divisao \n\t5 - sair \n -> Escolha uma opcao: ");
    scanf(" %d", &op);
    switch (op)
    {
        case 1:
            printf(" - Resultado %d \n", soma(n1, n2));
            break;
        case 2:
            printf(" - Resultado %d \n", subtracao(n1, n2));
            break;
        case 3:
            printf(" - Resultado %d \n", multiplicacao(n1, n2));
            break;
        case 4:
            if (n1 == 0)
                printf(" - Resultado operacao invalida \n");
            else
            {
                printf(" - Resultado %4.2f \n", divisao(n1, n2));
            }
            break;
        default:
            break;
    }
    return 0;
}
