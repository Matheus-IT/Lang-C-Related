#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n;
    int *v = NULL; //Esse ponteiro vai virar um vetor

    printf(" - Quantos valores vai precisar? ");
    scanf(" %d", &n);
    v = (int *)(malloc(n * sizeof(int))); //Alocando memoria
    if (v == NULL)
    {
        printf(" - Erro de alocacao de memoria!"); //Caso ocorra erro ao alocar memoria
        system("pause")
        exit(1);
    }
    for (int cont = 0; cont < n; cont++)
    {
        printf(" - Digite o valor da posicao %d: ", cont+1);
        scanf(" %d", &v[cont]);
    }
    for (int cont = 0; cont < n; cont++)
    {
        printf(" %d", v[cont]);
    }
    free(v); //Desalocando memoria
    return 0;
}
