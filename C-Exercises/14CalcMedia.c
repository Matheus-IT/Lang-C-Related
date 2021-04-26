#include <stdio.h>


int main(){
    int n1, n2;
    float m;

    printf("\nDigite a primeira nota: ");
    scanf("%d", &n1);
    printf("Digite a segunda nota: ");
    scanf("%d", &n2);
    m = (n1 + n2)/2;
    printf("Com notas %d e %d sua media e %.2f \n", n1, n2, m); //%4.2f -> Floats!
    if (m>=7)
    {
        printf("Resultado: Aluno aprovado!");
    }
    else
    {
        printf("Resultado: Aluno reprovado");
    }
    return 0;
}
