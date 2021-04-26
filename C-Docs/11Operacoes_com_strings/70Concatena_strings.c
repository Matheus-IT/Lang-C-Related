#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int concatenar(char p1[], int tp1, char p2[], int tam, char np[])
{
    for (int cont = 0; cont < tp1; cont++){
        np[cont] = p1[cont];
    }
    for (int cont = tp1, cont2 = 0; cont < tam; cont++, cont2++){
        np[cont] = p2[cont2];
    }
    return 0;
}


int main()
{
    char pl1[] = {"pao "};
    char pl2[] = {"mortadela"};
    char novaPl[13];
    /*
    //Usando biblioteca string.h
    strcpy(novaPl, pl1);
    strcat(novaPl, pl2);
    */
    //Sem usar a biblioteca string.h
    concatenar(pl1, 4, pl2, 13, novaPl);
    for (int cont = 0; cont < 13; cont++)
    {
        printf("%c", novaPl[cont]);
    }
    return 0;
}
