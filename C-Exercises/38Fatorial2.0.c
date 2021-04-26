#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>


int main()
{
    while (1)
    {   
        int n, fat = 1;

        system("cls");
        printf("====================================\n");
        printf("========= CALCULO FATORIAL =========\n");
        printf("====================================\n");
        printf("Fatorial de qual numero? ");
        scanf("%i", &n);
        if (n < 0)
        {
            n = abs(n); //Caso digitem um numero negativo
        }
        
        printf("%i! => ", n);
        for (n; n > 0; n--)
        {
            Sleep(500);
            if (n > 1)
            {
                printf("%i x ", n);
            }
            else
            {
                printf("%i = ", n);
            }
            fat *= n; //Calculo do fatorial
        }
        printf("%i \n", fat);
        Sleep(2000);

        char resp[] = "";
        printf(" - Quer condinuar? [S/N] ");
        scanf("%s", &resp);
        strcpy(resp, strupr(resp)); //Converte para UPPERCASE e copia para resp
        while ((resp[0] != 'S') && (resp[0] != 'N'))
        {
            printf(" - Opcao incorreta! Quer continuar? [S/N] ");
            scanf("%s", &resp);
            strcpy(resp, strupr(resp));
        }
        if (resp[0] == 'N')
        {
            break;
        }
    }
    printf("Tchau! :D \n");
    return 0;
}
