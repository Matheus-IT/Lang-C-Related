#include <stdio.h>


int main(){
    char sexo[40];
    printf("Digite seu sexo: ");
    scanf("%1s", sexo); //Pegar somente o primeiro caractere digitado
    printf("Seu sexo e: %s", sexo);
    return 0;
}
