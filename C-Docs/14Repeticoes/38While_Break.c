#include <stdio.h>
#include <stdlib.h>


int main(){
    int n = 0;
    system("cls"); //Limpa Tela
    while (1)
    {
        printf("%d \n", n);
        n++;
        if (n == 11)
        {
            printf("Terminei de contar!");
            break;
        }
    }
    return 0;
}
