#include <stdio.h>
#include <math.h>


int main(){
    float a, seno;
    const float pi = 3.141592;

    printf("\nDigite um angulo: ");
    scanf("%f", &a);
    seno = sin(a * (pi/180)); //Converte graus para radianos e calcula o seno
    printf("O seno de %4.2f e igual a %5.4f", a, seno);
    return 0;
}
