#include <Stdio.h>
#include <stdlib.h>
#include <time.h>

void preenche_vet(int v[10]);
void inverte_vet(int v[10]);

const int max = 9;

int main()
{
    int vet[10];

    system("cls");
    printf(" - Vetor normal: \n");
    preenche_vet(vet);
    printf("\n - Vetor invertido: \n");
    inverte_vet(vet);
    return 0;
}


void preenche_vet(int v[10])
{
    srand(time(NULL));
    for (int cont = 0; cont <= max; cont++)
    {
        v[cont] = rand()%9; //Números aleatórios entre 0 e 10
        printf(" (%d)", v[cont]);
    }
}


void inverte_vet(int v[10])
{
    int aux;

    for (int cont = 0, cont2 = max; cont <= max/2; cont++, cont2--)
    {
        aux = v[cont];
        v[cont] = v[cont2]; //Inverte o vetor1
        v[cont2] = aux;
    }
    for (int cont = 0; cont <= max; cont++)
    {
        printf(" (%d)", v[cont]);
    }
}
