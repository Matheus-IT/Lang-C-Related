#include <stdio.h>
#include <stdlib.h>


int say_hello(int n_times)
{
    for (int cont = 0; cont < n_times; cont++)
    {
        printf(" - Hello! \n");
    }
    return 0;
}


int main()
{
    int n = 0;
    int (*fPointer)(int); //Ponteiro da funcao

    fPointer = say_hello; //Atribuicao ao ponteiro
    printf(" - How many times? ");
    scanf("%d", &n);
    fPointer(n);
    return 0;
}
