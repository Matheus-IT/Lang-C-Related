#include <stdio.h>
#include <stdlib.h>


int main(){
    int op, n;
    char resp;

    system("cls");
    printf("\
=============== PROGRAMA TABUADA ===============\n\
 = [1]Soma\n\
 = [2]Subtracao\n\
 = [3]Multiplicacao\n\
 = [4]Divisao\n\
 - Qual operacao deseja realizar: ");
    scanf(" %d", &op);
    while ((op != 1) && (op != 2) && (op != 3) && (op != 4))
    {
        printf(" - Opcao invalida! Qual operacao deseja realizar? ");
        scanf(" %d", &op);
    }
    switch (op)
    {
    case 1:
        printf(" - Tabuada de SOMA de qual numero? ");
        scanf("%d", &n);
        for (int cont = 0; cont <= 10; cont++)
        {
            printf(" %d + %d = %d \n", n, cont, n+cont);
        }
        break;
    case 2:
        printf(" - Tabuada de SUBTRACAO de qual numero? ");
        scanf("%d", &n);
        for (int cont = 0; cont <= 10; cont++)
        {
            printf(" %d - %d = %d \n", n, cont, n-cont);
        }
        break;
    case 3:
        printf(" - Tabuada de MULTIPLICACAO de qual numero? ");
        scanf("%d", &n);
        for (int cont = 0; cont <= 10; cont++)
        {
            printf(" %d x %d = %d \n", n, cont, n*cont);
        }
        break;
    case 4:
        printf(" - Tabuada de DIVISAO de qual numero? ");
        scanf("%d", &n);
        for (float cont = 0; cont <= 10; cont++) //Terminar essa condicao
        {
            printf(" %d / %d = %4.2f \n", n, cont, (float)n/(float)cont);
        }
    }
    return 0;
}
