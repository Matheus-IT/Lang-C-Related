#include <stdio.h>
#include <stdlib.h>


int fibonacci(int num) //Declaracao e definicao da funcao
{
    int v[num];
    int a, b, c;
    a = b = c = 0;

    a = 0;
    b = 1;
    for (int cont = 0; cont < num; cont++)
    {
        c = a + b;
        a = b;
        b = c;
        v[cont] = c;
    }
    return v;
}


int mostrar_vetor(int v[], int num)
{
    for (int cont = 0; cont < num; cont++)
    {
        printf(" %d", v[cont]);
    }
}


int main()
{
    int n = 0;

    printf(" - Ver quantos digitos de fibonacci? ");
    scanf(" %d", &n);
    mostrar_vetor(fibonacci(n), n);
    return 0;
}
