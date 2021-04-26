#include <stdio.h>
#include <stdio.h>

const int tam = 3;

int func(int array[], int matriz[][tam]) 
/*
    Quando receber uma matriz, usar pelo 
    menos um dos espacos (pode tambem usar 
    todos os que ela tiver) 
*/
{   
    for (int  cont = 0;  cont < max; cont++)
    {
        printf("%s \n", p[cont]); 
        //Para matriz com strings nao preciso usar duas repeticoes
    }            
    return 0;
}


int main()
{
    int sou_uma_array[10]; //Uma array inteira de 10 posicoes
    /* Todos os elementos de uma array sao do MESMO TIPO */
    /* Para adicionar mais uma dimensao basta acrecentar mais um par de colchetes */
    int sou_uma_matriz[3][3];
    float precos[5] = {15.6, 12.7, 13.9}; //Outra forma de declaracao
    /* Valores nao utilizados serao definidos como 0 */
    printf(" - Terceiro valor: %f", precos[2]);
    int aux = sou_uma_array[1];
    sou_uma_array[1] = sou_uma_array[2];
    sou_uma_array[2] = aux;
    /* Os valores podem ser modificados ao atribuir usando os indices */
    /* Podemos tambem usar loopings para acessar os indeces */
    return 0;
}
