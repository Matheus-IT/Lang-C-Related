#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Preciso da biblioteca time.h


int main() {
    srand(time(NULL));
    for (int cont = 0; cont < 10; cont++) {
        printf(" (%d)", rand()%10); //10 números aleatórios entre 0 e 9
    }
    printf("\n");
    for (int cont = 0; cont < 10; cont++) {
        printf(" (%d)", (rand()%10)+1); //10 numeros aleatorios entre 1 e 10
    }
    return 0;
}
