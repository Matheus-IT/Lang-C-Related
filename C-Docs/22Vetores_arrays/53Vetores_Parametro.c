#include <stdio.h>
#include <stdlib.h>


void ordVetor(int v[], int n) //Vetores sempre sao recebidos como referencia
//void ordVetor(int *v, int n) //Tambem pode ser desse jeito, mesma coisa
{
    int aux;
    
    /* Organizando os valores em ordem crescente */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i] < v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}


void mostra_vetor(int v[], int n) //Vetores sempre sao recebidos como referencia
{
    for (int cont = 0; cont < n; cont++)
    {
        printf(" (%d)", v[cont]);
    }
}


int num = 10; //Variavel global


int main() //Programa principal
{
    int vetor[10] = {6, 4, 1, 9, 8, 0, 5, 7, 3, 2};
    ordVetor(vetor, num); //Vetores sempre sao passados como referencia
    mostra_vetor(vetor, num);
    return 0;
}
