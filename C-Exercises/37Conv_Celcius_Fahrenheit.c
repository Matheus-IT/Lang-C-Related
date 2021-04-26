#include <stdio.h>
#include <stdlib.h>


int main()
{
    float c, f;

    system("cls");
    printf("Quantos graus faz no estados unidos? ");
    scanf("%f", &f);
    c = (f - 32)/1.8;
    printf("No Brasil estaria %4.2f \n", c);
    return 0;
}
