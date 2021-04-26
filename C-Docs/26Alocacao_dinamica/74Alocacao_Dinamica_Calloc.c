#include <stdio.h>
#include <stdlib.h>


int main()
{
    int *p = NULL;
    p = (int *)(calloc(5, sizeof(int))); //1 - Quantos elementos alocar 2 - Tamanho de cada um
    for (int cont = 0; cont < 5; cont++)
    {
        //Se nao colocar nenhum valor ele comeca com cada elemento valendo 0
        printf(" %d", p[cont]);
    }
    return 0;
}
