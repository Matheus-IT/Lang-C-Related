#include <stdio.h>
#include <stdlib.h>


int main()
{
    int j = 63;
    int *p = NULL; //Ponteiros devem ser inicializados com NULL
    p = &j; //Ponteiros podem receber o endereco de uma variavel com &
    /*
       Some algorithms use a pointer to a pointer. This type of variable
       declaration uses **, and can be assigned the address of another 
       pointer, as in:
       
       int x = 12;
       int *p = NULL
       int **ptr = NULL; //Um ponteiro que contem um ponteiro
       p = &x;
       ptr = &p;
    */

    printf("O endereco de j e %x\n", &j);
    printf("p contem o endereco %x em exadecimal\n", p);
    printf("p contem o endereco %d em inteiro\n", p);
    printf("O valor de j e %d\n", j);
    printf("p esta apontando para o valor %d\n", *p); 

    return 0;
}
