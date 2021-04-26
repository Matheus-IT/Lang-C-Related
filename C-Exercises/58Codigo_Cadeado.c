#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int mostra(char v[])
{
    int tam = strlen(v);
    for (int cont = 0; cont < tam; cont++)
    {
        printf(" %c ", v[cont]);
    }
    printf("\n");
    return 0;
}


int tirar_repetidos(char s[]) //Tirar caracteres que se repetem em sequência
{
    bool primeiro = true;
    int inicio = 0;
    int tamanho = 0;
    for (int cont = 0; cont < strlen(s); cont++)
    {
        if ((s[cont] == s[cont+1]) && (s[cont] != 'a'))
        {
            if (primeiro == true) //Definir qual o primeiro da sequência de repetidos
            {
                inicio = cont;
                primeiro = false;
            }
        }
        else if ((s[cont] == s[cont-1]) && (s[cont] != 'a'))
        {
            tamanho = cont+1;
            break;
        }
    }
    int qtd = 0;
    if ((s[inicio] >= 'b') && (s[inicio] <= 'm')) //Contabilizar movimentos intervalo b - m
    {
        while (s[inicio] != 'a')
        {
            s[inicio] -= 1;
            qtd++; //Quantidade de movimentos
        }
    }
    else if ((s[inicio] >= 'n') && (s[inicio] <= 'z')) //Contabilizar intervalo n - z
    {
        while (s[inicio] != 'a')
        {
            if (s[inicio] == 'z')
                s[inicio] -= 25;
            else
            {
                s[inicio] += 1;
            }
            qtd++; //Quantidade de movimentos
        }
    }
    for (int cont = inicio; cont < tamanho; cont++)
    {
        s[cont] = 'a';
    }
    return qtd;
}


bool tem_repetidos(char s[]) //Diz se tem caracteres repetidos no vetor
{
    bool result = false;
    int tam = strlen(s);
    for (int cont = 0; cont < tam-1; cont++)
    {
        if ((s[cont] == s[cont+1]) && (s[cont] != 'a'))
            result = true;
    }
    return result;
}


int organiza(char s[])
{
    int qtd = 0;
    int tam = strlen(s);
    while (tem_repetidos(s)) //Tirar todas sequências de repetidos e contar os movimentos
    {
        qtd += tirar_repetidos(s);
    }
    for (int cont = 0; cont < tam; cont++)
    {
        if ((s[cont] >= 'b') && (s[cont] <= 'm')) //Contabilizar movimentos intervalo b - m
        {
            while (s[cont] != 'a')
            {
                s[cont] -= 1;
            }
            qtd++; //Quantidade de movimentos
        }
    }
    for (int cont = 0; cont < tam; cont++)
    {
        if ((s[cont] >= 'n') && (s[cont] <= 'z')) //Contabilizar intervalo n - z
        {
            while (s[cont] != 'a')
            {
                if (s[cont] == 'z')
                    s[cont] -= 25;
                else
                {
                    s[cont] += 1;
                }
            }
            qtd++; //Quantidade de movimentos
        }
    }
    return qtd;
}


int main()
{
    /* nopqrstuvwxyz abcdefghijklm */
    char *seq;
    seq = (char *)(malloc(100 * sizeof(char)));
    printf(" - Digite a sequencia: ");
    fgets(seq, 100, stdin);
    printf(" - Antes: \n");
    mostra(seq);
    int n_movimentos = organiza(seq);
    printf(" - Depois: \n");
    mostra(seq);
    printf(" - Numero de movimentos %d ", n_movimentos);
    free(seq);
    return 0;
}
