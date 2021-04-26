#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


int main(){
    time_t segundos;
    struct tm *data_hora;
    time(&segundos);
    data_hora = localtime(&segundos);
    int a_atual = data_hora -> tm_year+1900;
    int a_nasc, idade;

    
    printf("\n \
============================================================\n \
================= DEPARTAMENTO DE TRANSITO =================\n \
============================================================\n");
    printf("Ola, informe seu ano de nascimento: ");
    scanf("%d", &a_nasc);
    printf("Hum... ");
    Sleep(1000); // -> 1 Segundo
    idade = a_atual - a_nasc; 
    printf("Certo, voce tem %d anos \n", idade);
    Sleep(1000);
    printf("=============================================================\n");
    if (idade >= 18)
    {
        printf("Aqui diz que voce e apto a tirar a carteira de motorista :) \n");
    }
    else
    {
        printf("Infelizmente voce ainda nao pode tirar a carteira :C \n");
        if (18 - idade > 1)
        {
            printf("Ainda faltam %d anos para voce tirar a sua \n", 18-idade);
        }
        else
        {
            printf("Relaxa, so falta 1 ano pra voce tirar a sua \n");
        }
    }
    return 0;
}
