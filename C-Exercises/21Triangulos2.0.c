#include <stdio.h>


int main(){
    float la, lb, lc;

    printf("\n======== Programa Triangulos 2.0 ========\n");
    printf("\nDigite o primeiro lado do triangulo: ");
    scanf("%f", &la);
    printf("Digite o segundo lado do triangulo: ");
    scanf("%f", &lb);
    printf("Digite o terceiro lado do triangulo: ");
    scanf("%f", &lc);
    
    if ((la < lb+lc) && (lb < la+lc) && (lc < la+lb)) //Condicao para formar triangulos
    {
        if ((la == lb) && (lb == lc)) //Todos lados iguais
        {
            printf("Estes lados formam um triangulo EQUILATERO \n");
        }
        else
        {
            if ((la == lb) || (la == lc) || (lb == lc)) //Pelo menos dois iguais
            {
                printf("Estes lados formam um triangulo ISOSCELES \n");
            }
        }
        
        if ((la != lb) && (lb != lc) && (la != lc)) //Todos lados diferentes
        {
            printf("Estes lados formam um triangulo ESCALENO \n");
        }
    }
    else
    {
        printf("Os tres lados digitados NAO PODEM formar um triangulo!");
    }
    return 0;
}
