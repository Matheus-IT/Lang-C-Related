#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *texto = NULL;
    texto = fopen("numero.txt", "r"); // "r" para leitura ,"w" para escrita
    if (texto == NULL) //Caso o arquivo procurado nao exista
    {
        printf(" - Nao foi possivel abrir o arquivo \n");
    }
    else
    {
        int x, y, z;
        fscanf(texto, " %d %d %d", &x, &y, &z); //Pegar os tres numeros de numero.txt
        printf(" %d %d %d \n", x, y, z);
    }
    fclose(texto);
    return 0;
}
