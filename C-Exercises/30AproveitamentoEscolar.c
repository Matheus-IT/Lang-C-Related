#include <stdio.h>
#include <stdlib.h>


int main(){
    float n1, n2, n3, m;

    printf("\
======================================================\n\
=============== COLEGIO JAVALI CANSADO ===============\n\
======================================================\n");
    printf(" - Digite a primeira nota: ");
    scanf("%f", &n1);
    printf(" - Digite a segunda nota: ");
    scanf("%f", &n2);
    printf(" - Digite a terceira nota: ");
    scanf("%f", &n3);
    m = (n1 + n2 + n3)/3; //Calculo da media
    printf("======================================================\n");
    printf("=> Sua media e igual a %4.2f \n", m);
    if (m >= 9)
    {
        printf("E seu aproveitamento e A, parabens continue assim");
    }
    else if ((m >= 8) && (m <= 8.9))
    {
        printf("E seu aproveitamento e B, parabens");
    }
    else if ((m >= 7) && (m <= 7.9))
    {
        printf("E seu aproveitamento e C, bom trabalho");
    }
    else if ((m >= 6) && (m <= 6.9))
    {
        printf("E seu aproveitamento e D, voce pode melhorar");
    }
    else if ((m >= 5) && (m <= 5.9))
    {
        printf("E seu aproveitamento e E, continue tentando");
    }
    else
    {
        printf("E seu aproveitamento e F, nao foi dessa vez");
    }
    printf("\n");
    return 0;
}
