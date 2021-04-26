#include <stdio.h>


int main(){
    int n;

    printf("\nDigite um numero inteiro: ");
    scanf("%d", &n);
    if (n % 10 == 0) //Condição para que seja redondo
    {
        printf("O numero %d E redondo \n", n);
    }
    else
    {
        printf("O numero %d NAO E redondo \n", n);
    }
    return 0;
}
