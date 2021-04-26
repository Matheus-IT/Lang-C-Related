#include <stdio.h>
#include <stdlib.h>

/* Variaveis globais sempre ficam aqui em cima */
int global = 0; //Variavel global

int main()
{
    int local1, local2; //Variaveis locais

    local1 = 5;
    local2 = 10;
    global = local1 + local2;
    printf("%d \n", global);
    return 0;
}
