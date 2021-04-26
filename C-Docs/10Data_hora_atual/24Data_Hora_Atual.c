#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Biblioteca para conseguir o ano


int main(){
    time_t segundos; //Variável para pegar os segundos
    struct tm *data_hora; //Ponteiro para armazenar data e hora
    time(&segundos); //Pegando o tempo em segundos
    data_hora = localtime(&segundos); //Converter segundos para formato data

    printf("\nAno atual %i \n", data_hora -> tm_year + 1900); // ->tm_year+1900 Adicionar 1900 para pegar o ano corretamente!
    //Or i can do this: 
    printf(" %s", __DATE__);
    return 0;
}
