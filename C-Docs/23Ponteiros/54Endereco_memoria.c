#include <stdio.h>
#include <stdlib.h>


void test(int k)
{
    printf("O endereco de k e %x\n", &k);
}


int main()
{
    int i = 0;
    
    /* %x e o especificador de formato */
    printf("O endereco de i e %x\n", &i);
    test(i);
    printf("O endereco de i e %x\n", &i);
    test(i);
    /* O endereco de memoria da variavel 
    continua o mesmo desde a declaracao 
    ate o fim do seu escopo  */
    return 0;
}
