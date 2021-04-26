#include <stdio.h>
#include <stdlib.h>


int main(){
    system("cls"); //Limpar Tela
    for (int cont = 0; cont <= 10; cont++)
    {
        if (cont == 5)
        {
            printf("Nao vou mostrar :D \n");
            continue; //Volta para o topo do bloco de instrucao
        }
        printf("%i \n", cont);
    }
    return 0;
}
