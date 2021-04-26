#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int max = 9;


int proc_val(int num, int *v) //Passando vetor como uma referencia
{
    int ns = 0;
    for ( int cont = 0; cont <= max; cont++)
    {
        if (v[cont] == num)
        {
            printf(" - Achei o valor %d na posicao %d \n", v[cont], cont);
            ns += 1;
        }
        else if ((cont == max) && (ns == 0))
        {
            printf(" - Nao achei! :(\n");
        }
    }
}


int main()
{
    int vet[max];
    char resp[5] = "S";
    int n;
    n = 0;

    srand(time(NULL));
    system("cls");
    for (int cont = 0; cont <= max; cont++)
    {
        n = rand()%9;
        vet[cont] = n;
        printf(" (%d)", vet[cont]);
    }
    printf("\n");
    while (resp[0] == 'S')
    {
        printf(" - Procurar qual valor? ");
        scanf(" %d", &n);
        proc_val(n, vet);
        printf(" - Procurar mais um valor? [S/N] ");
        fflush(stdin);
        gets(resp);
        strcpy(resp, strupr(resp));
        while ((resp[0] != 'S') && (resp[0] != 'N'))
        {
            printf(" - Opcao invalida! Procurar mais um valor? [S/N] ");
            fflush(stdin);
            gets(resp);
            strcpy(resp, strupr(resp));
        }
    }
    return 0;
}
