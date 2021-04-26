#include <stdio.h>
#include <ctype.h>


int main(){
    char nome[50], sexo;

    printf("\nDigite seu nome: ");
    gets(nome);
    printf("Digite o seu sexo: ");
    sexo = getchar();
    char sexoUp = toupper(sexo);
    while ((sexoUp != 'M') && (sexoUp != 'F'))
    {
        printf("Voce errou, digite o seu sexo: \n");
        sexo = getchar();
        sexoUp = toupper(sexo);
    }
    printf("O seu nome e %s e seu sexo e %c \n", nome, sexoUp);
    return 0;
}
