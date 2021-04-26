#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main() {
    /*
        //Retorna quantas posicoes tem o vetor:
            int v[qtd];
            length = sizeof(v)/sizeof(v[0]);
    */

    int qtd = 0;
    printf(" - Criar v com quantas posicoes? ");
    scanf(" %d", &qtd);
    int v[qtd];
    //Retorna quantas posicoes tem o vetor
    printf(" - Vetor tem tamanho: %d\n", sizeof(v)/sizeof(v[0]));
    return 0;
}
