#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>


int main(){
    float imc, weigh, hight;

    printf("\n==================== CALCULO IMC ====================\n");
    printf(" - Digite seu peso Kg: ");
    scanf("%f", &weigh);
    printf(" - Digite sua altura: ");
    scanf("%f", &hight);
    imc = weigh / pow(hight, 2);
    printf(" => Seu IMC e igual a %4.2f \n", imc);
    printf("Analisando seu IMC...");
    Sleep(2000);

    if (imc < 17)
    {
        printf("Voce esta muito abaixo do peso!! :o");
    }
    else if ((imc >= 17) && (imc <18))
    {
        printf("Voce esta abaixo do peso!");
    }
    else if ((imc >= 18.5) && (imc < 25))
    {
        printf("Voce esta no seu peso ideal :D");
    }
    else if ((imc >= 25) && (imc < 30))
    {
        printf("Voce esta com sobrepeso!");
    }
    else if ((imc >= 30) && (imc < 35))
    {
        printf("Voce esta em obesidade!!");
    }
    else if ((imc >= 35) && (imc < 40)){
        printf("Voce esta em obesidade severa!!!");
    }
    else if (imc >= 40)
    {
        printf("Voce esta em obesidade morbida!!!! :O");
    }
    printf("\n");
    return 0;
}
