#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


bool ja_tem(int val, int v[], int num)
{
    int tam = num;
    for (int cont = 0; cont < tam; cont++)
    {
        if (v[cont] == val)
        {
            return true;
        }
    }
    return false;
}


int * preencher_sequencia(int num)
{
    int *vet = NULL;
    vet = (int *)(malloc(num * sizeof(int)));
    for (int cont = 0; cont < num; cont++)
        {
            printf(" - Digite o valor para a posicao %d: ", cont+1);
            scanf(" %d", &vet[cont]);
        }
    return vet;
}


int * gerar_sequencia(int num)
{
    int *vet = NULL;
    int aleatorio = 0;
    srand(time(NULL));
    vet = (int *)(malloc(num * sizeof(int))); //Alocar vetor de num posições

    for (int cont = 0; cont < num; cont++)
    {
        aleatorio = (rand()%num)+1; //Numero aleatório entre 1 e 9
        while (ja_tem(aleatorio, vet, num)) //Verificar se ele ja esta na lista
        {
            aleatorio = (rand()%num)+1;
        }
        vet[cont] = aleatorio;
    }
    return vet;
}


int mostrar(int seq[], int num)
{
    printf("\n");
    for (int cont = 0; cont < num; cont++)
    {
        printf(" (%d)", seq[cont]);
    }
    return 0;
}


bool em_ordem(int seq[], int num)
{
    for (int i = 0; i < num; i++)
    {
        for (int j = i; j < num; j++)
        {
            if (seq[i] > seq[j])
            return false;
        }
    }
    return true;
}


int ordenar(int seq[], int num)
{
    int aux = 0;
    int qtd = 0;
    while (!em_ordem(seq, num)) //Enquanto a sequencia nao estiver em ordem
    {
        for (int i = 0, j = i+1; i < num-1; i++,j++)
        {
            if (seq[i] > seq[j])
            {
                aux = seq[i];
                seq[i] = seq[j];
                seq[j] = aux;
                qtd++;
            }
        }         
    }
    return qtd;
}


int main()
{
    int n = 0;
    int escolha = 0;
    int *sequencia = NULL;
    
    printf(" - Digite um numero aleatorio N: ");
    scanf(" %d", &n);
    while ((n < 2) || (n > 100000))
    {
        printf(" - Entrada invalida! Digite um numero aleatorio N: ");
        scanf(" %d", &n);
    }
    printf(" [1] - Digitar sequencia\n [2] - Gerar automaticamente\n - Escolha: ");
    scanf(" %d", &escolha);
    switch (escolha)
    {
        case 1:
            sequencia = preencher_sequencia(n);
        break;
        case 2:
            sequencia = gerar_sequencia(n);
        break;
    }
    mostrar(sequencia, n);
    int qtd = ordenar(sequencia, n);
    mostrar(sequencia, n);
    printf("\n - Quantidade de trocas necessarias %d\n", qtd);
    if (qtd % 2 == 0)
        printf(" - Vencedor e Carlos\n");
    else
    {
        printf(" - Vencedor e Marcelo\n");
    }
    free(sequencia);
    return 0;
}
