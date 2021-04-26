#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v1, v2;

    printf(" - Digite o primeiro valor: ");
    scanf(" %d", &v1);
    printf(" - Digite o segundo valor: ");
    scanf(" %d", &v2);
    if (v1 < v2)
    {
        for (int cont = v1; cont <= v2; cont++)
        {
            printf(" %d ", cont);
        }
    }
    else
    {
        for (int cont = v1; cont >= v2; cont--)
        {
            printf(" %d ", cont);
        }
    }
    return 0;
}
