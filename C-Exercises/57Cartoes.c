#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int avaliar(unsigned int *nc)
{
    while ((*nc < 2) || (*nc > 10000) || (*nc % 2 == 1))
    {
        if (*nc < 2)
        {
            printf(" - Precisa de pelo menos 2 cartoes! Quantos cartoes estao sobre a mesa? ");
            scanf(" %d", nc);
        }
        else if (*nc > 10000)
        {
            printf(" - Cartoes demais (Maximo de 10000)!\n - Quantos cartoes estao sobre a mesa? ");
            scanf(" %d", nc);
        }
        else if (*nc % 2 == 1)
        {
            printf(" - O numero de cartoes tem de ser par!\n - Quantos cartoes estao sobre a mesa? ");
            scanf(" %d", nc);
        }
    }
    return 0;
}


double * colocar_cartoes(unsigned int nc)
{
    double *vet = NULL;
    vet = (double *)(malloc(nc * sizeof(double))); //Vetor alocado dinamicamente

    for (int cont = 0; cont < nc; cont++)
    {
        printf(" - Qual o %do cartao? ", cont+1);
        scanf(" %lf", &vet[cont]);
        while ((vet[cont] < -32768) || (vet[cont] > 32767))
        {
            if (vet[cont] < -32768)
            {
                printf(" - Minimo de -32768! Qual o %do cartao? ", cont+1);
                scanf(" %lf", &vet[cont]);
            }
            else if (vet[cont] > 32767)
            {
                printf(" - Maximo de 32767! Qual o %do cartao? ", cont+1);
                scanf(" %lf", &vet[cont]);
            }
        }
    }
    return vet;
}


int mostrar(double m[], int nc)
{
    printf("\n");
    for (int cont = 0; cont < nc; cont++)
        printf(" %2.0lf", m[cont]);
    return 0;
}


int tirar_maior_das_pontas(double m[], int *nc) //'Apaga' o maior valor das pontas e retorna os pontos
{
    int p = 0;
    if (m[0] >= m[*nc-1])
    {
        p = m[0]; //Salvar os pontos antes de apagar
        for (int cont = 0; cont < *nc; cont++)
        {
            m[cont] = m[cont+1];
        }
        *nc -= 1; //Descontar removido
    }
    else if (m[*nc-1] > m[0])
    {
        p = m[*nc-1]; //Salvar os pontos antes de apagar
        m[*nc-1] = m[*nc];
        *nc -= 1; //Descontar removido
    }
    return p;
}


int pontos_neymar(double m[], int nc)
{
    int tot_pontos = 0;
    bool vez_de_neymar = true;
    while (nc > 0) //Enquanto tiver cartoes para tirar
    {
        if (vez_de_neymar)
        {
            tot_pontos += tirar_maior_das_pontas(m, &nc);
            vez_de_neymar = false;
        }
        else
        {
            tirar_maior_das_pontas(m, &nc);
            vez_de_neymar = true;
        } 
    }
    return tot_pontos;
}


int main()
{
    int unsigned n = 0;
    int p = 0;
    double *mesa = NULL;

    printf(" - Quantos cartoes estao sobre a mesa? ");
    scanf(" %d", &n);
    avaliar(&n); //Verificar se o valor se encaixa nas condicoes
    mesa = colocar_cartoes(n); //Colocar os cartoes na mesa
    mostrar(mesa, n);
    p = pontos_neymar(mesa, n); //Maior numero de pontos que neymar consegue obter
    printf("\n - O maior numero de pontos de neymar e: %d", p);
    return 0;
}
