#include <stdio.h>
#include <stdlib.h>


int main(){

    /*
        1) char
        2) int
        3) float
        4) double
        5) void

        1) signed   -> + e - (positivos e negativos)
        2) unsigned -> + (so positivos)
        3) long     -> aumenta a capacidade de armazenamento
        4) short    -> diminuir a capacidade de armazenamento
    */

    int i;
    unsigned short int u; //Diminuir metade da capacidade e tira os numeros negativos

    printf("\n%d Bytes -> tamanho de i \n", sizeof(i));
    printf("%d Bytes -> tamanho de u \n", sizeof(u));
    return 0;
}
