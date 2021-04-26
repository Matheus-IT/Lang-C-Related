#include <stdio.h>
#include <stdlib.h>


int main(){
    int ini, fin, pas;

    printf("\
====================================================\n\
=============== CONTADOR INTELIGENTE ===============\n\
====================================================\n");
    printf(" - Qual o INICIO da contagem? ");
    scanf("%d", &ini);
    printf(" - Qual o FINAL da contagem? ");
    scanf("%d", &fin);
    printf(" - Qual o PASSO da contagem? ");
    scanf("%d", &pas);
    if (ini < fin)
    {
        for (ini; ini <= fin; ini += pas)
        {
            printf("%d \n", ini);
        }
    }
    else if (ini > fin)
    {
        for (ini; ini >= fin; ini -= pas)
        {
            printf("%d \n", ini);
        }
    }
    printf("Terminei de contar \n");
    return 0;
}
