#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float dist_dia;
    float dist_semana;
    float valor_ano; //Value displayed as kilometers
} distancia_anual;

void calcular_valor_ano(distancia_anual *dist_ano, float dist) {
    dist_ano->dist_dia = dist * 2;
    dist_ano->dist_semana = dist_ano->dist_dia * 5;
    dist_ano->valor_ano = (dist_ano->dist_semana * 45)/1000;
}

int main() {
    float dist;
    distancia_anual dist_ano;
    printf(" - Qual a sua distancia de casa ate o trabalho em metros? ");
    scanf(" %f", &dist);
    calcular_valor_ano(&dist_ano, dist);
    printf(" - Depois de um ano com sua rotina, voce tera andado %4.2fkm", dist_ano.valor_ano);
}
