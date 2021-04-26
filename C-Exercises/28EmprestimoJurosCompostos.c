#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>


int main(){
    int emprestimo, parcelas;
    float juros, montante;

    printf("\n\
===========================================\n\
============ BANCO ROUBA POUCO ============\n\
===========================================\n");

    printf(" - Quanto sera o valor do emprestimo? ");
    scanf("%d", &emprestimo);
    printf(" - Quanto sera o valor de juros? %%: ");
    scanf("%f", &juros);
    juros = (juros/100); //Converter em porcento
    printf(" - Vai pagar em quantas parcelas? ");
    scanf("%d", &parcelas);
    montante = emprestimo * pow(1 + juros, parcelas); //Calculo do montante final
    Sleep(2000); //2 Segundos
    printf("===========================================\n");
    printf("O valor do montante e igual a %3.2f \n", montante);
    return 0;
}
