#include <stdio.h>


int main(){
    float la, lb, lc;

    printf("\nDigite o primeiro lado: ");
    scanf("%f", &la);
    printf("Digite o segundo lado: ");
    scanf("%f", &lb);
    printf("Digite o terceiro lado: ");
    scanf("%f", &lc);

    if ((la<lb+lc) && (lb<la+lc) && (lc<la+lb))
    {
        printf("Os lados digitados PODEM formar um triangulo! \n");
    }
    else
    {
        printf("Os lados digitados NAO PODE formar um triangulo! \n");
    }
    return 0;
}
