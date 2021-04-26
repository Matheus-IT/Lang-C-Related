#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


//DECLARACAO DE FUNCOES
float kelvin_celcius();
float celcius_kelvin();
float celcius_fahrenheit();
float fahrenheit_celcius();
float kelvin_fahrenheit();
float fahrenheit_kelvin();


int main()
{
    while (1)
    {
        //Variaveis locais da main()
        char resp[6];
        int op, escala;
        escala = op = 0;

        system("cls");
        printf("\
=================================================================\n\
============= CONVERSOR TEMPERATURA NAO E CALOR :D ==============\n\
=================================================================\n\
   [1] Kelvin <==> Celcius\n\
   [2] Celcius <==> Fahrenheit\n\
   [3] Kelvin <==> Fahrenheit\n\
   [4] Sair\n\
    - Qual conversao deseja fazer? ");
        scanf("%d", &op);
        while ((op != 1) && (op != 2) && (op != 3) && (op != 4)) //Tratando erros de digitacao
        {
            printf("    - Opcao incorreta! Qual conversao deseja fazer? ");
            scanf("%d", &op);
        }

        system("cls");
        switch (op)
        {
        case 1: //Kelvin <==> Celcius
            printf("\
=================================================================\n\
====================== Kelvin <==> Celcius ======================\n\
=================================================================\n\
 - Kelvin  => Celcius [1]\n\
 - Celcius => Kelvin  [2]\n\
 - Escolha: ");
            scanf(" %d", &escala);
            switch (escala)
            {
            case 1:
                kelvin_celcius();
                break;
            case 2:
                celcius_kelvin();
                break;
            default:
                printf(" - Nao entendi \n");
                break;
            }
            break;
        case 2: //Celcius <==> Fahrenheit
            printf("\
=================================================================\n\
===================== Celcius <==> Fahrenheit ===================\n\
=================================================================\n\
 - Celcius    => Fahrenheit [1]\n\
 - Fahrenheit => Celcius    [2]\n\
 - Escolha: ");
            scanf(" %d", &escala);
            switch (escala)
            {
            case 1:
                celcius_fahrenheit();
                break;
            case 2:
                fahrenheit_celcius();
                break;
            default:
                printf(" - Nao entendi \n");
                break;
            }
            break;
        case 3: //Kelvin <==> Fahrenheit
            printf("\
=================================================================\n\
====================== Kelvin <==> Fahrenheit ===================\n\
=================================================================\n\
 - Kelvin     => Fahrenheit [1]\n\
 - Fahrenheit => Kelvin     [2]\n\
 - Escolha: ");
            scanf(" %d", &escala);
            switch (escala)
            {
            case 1:
                kelvin_fahrenheit();
                break;
            case 2:
                fahrenheit_kelvin();
                break;
            default:
                printf(" - Nao entendi \n");
                break;
            }
            break;
        }

        //Saindo do programa
        if (op == 4)
        {
            printf("Tchau!! :D \n");
            break;
        }
        printf("    Mais conversoes? [S/N] ");
        scanf(" %s", &resp);
        strcpy(resp, strupr(resp));
        while ((resp[0] != 'S') && (resp[0] != 'N')) //Tratando erros de digitacao
        {
            printf("    Opcao incorreta!! Mais conversoes? [S/N] ");
            scanf(" %s", &resp);
            strcpy(resp, strupr(resp));
        }
        if (resp[0] == 'N')
        {
            printf("Tchau!! :D \n");
            break;
        }
    }
    return 0;
}


//DEFINICOES DAS FUNCOES
float kelvin_celcius()
{
    //Variaveis locais
    float k, c;
    k = c = 0;


    system("cls");
    printf("\
=================================================================\n\
======================= Kelvin => Celcius =======================\n\
=================================================================\n\
 - Digite a temperatura em Kelvin: ");
    scanf(" %f", &k);
    printf("Hum... Deixe-me ver... \n");
    Sleep(2000);
    c = k - 273.15;
    printf("=> Resultado: %4.2fC \n", c);
    return 0;
}


float celcius_kelvin()
{   
    //Variaveis locais
    float k, c;
    k = c = 0;

    system("cls");
    printf("\
=================================================================\n\
======================= Celcius => Kelvin =======================\n\
=================================================================\n\
 - Digite a temperatura em Celcius: ");
    scanf(" %f", &c);
    printf("Hum... Deixe-me ver... \n");
    Sleep(2000);
    k = c + 273.15;
    printf("=> Resultado: %4.2fK \n", k);
    return 0;
}


float celcius_fahrenheit()
{
    //Variaveis locais
    float c, f;
    c = f = 0;

    system("cls");
    printf("\
=================================================================\n\
===================== Celcius => Fahrenheit =====================\n\
=================================================================\n\
 - Digite a temperatura em Celcius: ");
    scanf(" %f", &c);
    printf("Hum... Deixe-me ver... \n");
    Sleep(2000);
    f = 1.8*c + 32;
    printf("=> Resultado: %4.2ff \n", f);
    return 0;
}


float fahrenheit_celcius()
{
    //Variaveis locais
    float c, f;
    c = f = 0;

    system("cls");
    printf("\
=================================================================\n\
===================== Fahrenheit => Celcius =====================\n\
=================================================================\n\
 - Digite a temperatura em Fahrenheit: ");
    scanf(" %f", &f);
    c = (f-32)/1.8;
    printf("Hum... Deixe-me ver... \n");
    Sleep(2000);
    printf("=> Resultado: %4.2fC \n", c);
    return 0;
}


float kelvin_fahrenheit()
{
    //Variaveis locais
    float k, f;
    k = f = 0;

    system("cls");
    printf("\
=================================================================\n\
===================== Kelvin => Fahrenheit ======================\n\
=================================================================\n\
 - Digite a temperatura em Kelvin: ");
    scanf(" %f", &k);
    f = (k - 273.15) * 1.8 + 32;
    printf("Hum... Deixe-me ver... \n");
    Sleep(2000);
    printf("=> Resultado: %4.2f \n", f); 
    return 0;
}


float fahrenheit_kelvin()
{
    //Variaveis locais
    float k, f;
    k = f = 0;

    system("cls");
    printf("\
=================================================================\n\
===================== Fahrenheit => Kelvin ======================\n\
=================================================================\n\
 - Digite a temperatura em Fahrenheit: ");
    scanf(" %f", &f);
    k = (f - 32)/1.8 + 273.15;
    printf("Hum... Deixe-me ver... \n");
    Sleep(2000);
    printf("=> Resultado: %4.2fk \n", k);
    return 0;
}
