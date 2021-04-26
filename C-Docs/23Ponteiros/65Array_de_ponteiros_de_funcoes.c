#include <stdio.h>
#include <stdlib.h>


int soma(int n1, int n2)
{
    return n1 + n2;
}


int subtracao(int n1, int n2)
{
    return n1 - n2;
}


int multiplicacao(int n1, int n2)
{
    return n1 * n2;
}


int divisao(int n1, int n2)
{
    if (n1 != 0)
    {
        return n1 / n2;
    }
    else
    {
        return 0;
    }
}


int main()
{
    int num1, num2, escolha, r;
    int (*op[4])(int, int);

    op[0] = soma;
    op[1] = subtracao;
    op[2] = multiplicacao;
    op[3] = divisao;

    printf(" - Digite o primeiro numero: ");
    scanf(" %d", &num1);
    printf(" - Digite o segundo numero: ");
    scanf(" %d", &num2);
    printf(" - Escolha:\n 1 - Somar \n 2 - Subtrair \n 3 - Multiplicar \n 4 - Dividir \n =>> ");
    scanf(" %d", &escolha);
    r = op[escolha-1](num1, num2);
    printf(" Resultado: %d\n", r);
    return 0;
}
