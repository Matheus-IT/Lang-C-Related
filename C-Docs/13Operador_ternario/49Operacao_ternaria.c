#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main()
{
    char caractere = 0, codigo = 0;

    printf(" - Digite uma letra entre A e E: ");
    scanf(" %c", &caractere);
    caractere = toupper(caractere);
    codigo = (caractere == 'A') ? 65 : //Estrutura de controle com operador ternario
    (caractere == 'B') ? 66 :
    (caractere == 'C') ? 67 :
    (caractere == 'D') ? 68 :
    (caractere == 'E') ? 69 : -1;
    /*
    switch (caractere)
    {
        case 'A':
            codigo = 65;
            break;
        case 'B':
            codigo = 66;
            break;
        case 'C':
            codigo = 67;
            break;
        case 'D':
            codigo = 68;
            break;
        case 'E':
            codigo = 69;
            break;
    }
    */
    printf(" - O codigo de %c e %d", caractere, codigo);
    return 0;
}
