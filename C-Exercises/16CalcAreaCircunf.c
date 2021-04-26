#include <stdio.h>
#include <math.h>


int main(){
    float area, raio;
    const float pi = 3.14;

    printf("\nDigite o valor do raio da circunferencia: ");
    scanf("%f", &raio);

    area = pi * pow(raio, 2);
    printf("O valor da area e: %5.2f", area);
}
