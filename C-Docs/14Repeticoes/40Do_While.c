#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(){
    /*
        faca <- pelo menos uma vez :D
        {

        }
        enquanto (1);
    */

    int cont = 0;
    char carac;

    do
    {
        cont += 1;
        printf("%i vezes \n", cont);
        printf("Digite 0 para sair do looping \n");
        fflush(stdin); //Limpar o buffer
        carac = getchar();
    }
    while (carac != '0');
    return 0;
}
