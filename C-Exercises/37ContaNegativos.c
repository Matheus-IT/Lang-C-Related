#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


int main()
{   
    int n, cont = 0 , qtdNeg = 0;
    char resp[] = "";

    do
    {
        system("cls"); //Limpa tela
         printf("=============== CONTA NEGATIVOS ===============\n");
        printf(" - Digite o %do valor: ", cont+1);
        scanf("%d", &n);
        cont++;
        
        if (n < 0)
        {
            qtdNeg++;
        } 
        
        printf(" - Quer continuar? [S/N] ");
        scanf("%s", &resp);
        strcpy(resp, strupr(resp)); //Converter para UPPERCASE e copiar para resp
        while ((resp[0] != 'S') && (resp[0] != 'N')) //Caso erro de digitacao
        {
            printf(" - Opcao incorreta! Quer continuar? [S/N] ");
            scanf("%s", &resp);
            strcpy(resp, strupr(resp));
        }
        if (resp[0] == 'N')
        {
            break;
        }
    } while (1);
    printf("===============================================\n");
    printf(" => O total de numeros negativos e de %d \n", qtdNeg);
    printf("===============================================\n");
    printf(" => Tchau! :D \n");
    Sleep(1000);
    return 0;
}
