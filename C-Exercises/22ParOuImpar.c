#include <stdio.h>


int main(){
    int n;

    printf("\n======== Par ou impar ========\n");
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);
    if (n % 2 == 0) //O resto da divisao é um número inteiro
    {
        printf("O numero %d e par \n", n);
    }
    else
    {
        printf("O numero %d e impar \n", n);
    }
    return 0;
}
