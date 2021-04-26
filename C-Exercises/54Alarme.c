#include <stdio.h>
#include <stdlib.h>


int calc_TMin(int h[], int m[]) //Funcao que calcula o total de minutos
{
    int result = 0;

    for (int cont = 0; cont < 2; cont++) 
    {
        if (h[cont] == 0)
        {
            h[cont] = 24;
        }
    }
    if ((h[0] == h[1]) && (m[0] > m[1]))
    {
        result += 24*60;
    }
    result += 60 * (h[1] - h[0]) + (m[1] - m[0]);
    return result;
}


int main()
{
    int hrs[2] = {0, 0};
    int min[2] = {0, 0};
    int tot_Min = 0; 
    
    for (int cont = 0; cont < 2; cont++)
    {
        printf(" - Digite as horas: ");
        scanf(" %d", &hrs[cont]);
        printf(" - Digite os minutos: ");
        scanf(" %d", &min[cont]);
    }
    tot_Min = calc_TMin(hrs, min);
    printf(" - Total de minutos de sono: %d\n", tot_Min);
    return 0;
}
