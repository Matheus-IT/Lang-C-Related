#include <stdio.h>
#include <stdlib.h>

int main(){
    //getchar(); -> Pegua o próximo valor caractere digitado
    /*
        printf("Digite um valor: ");
        char a = getchar();
        printf("Voce digitou %c", a);
        return 0;
    */

    //gets(); -> Usado para ler strings!
    /*
        char a[40]; //Cadeia de caracteres ou String!
        printf("Digite seu nome: ");
        gets(a);
        printf("Ola %s e um prazer te conhecer! \n", a);
    */
    
    //scanf(); -> Usado para escanear valores especificos
    //scanf("%tipo_de_entrada", &qual_variavel_que_recebera);
    //A funcao scanf(); so le ate o primeiro ESPACO
    /*
        int num1, num2;
        printf("Digite um numero: ");
        scanf("%i", &num1);
        printf("Digite outro numero: ");
        scanf("%i", &num2);
        int soma = num1 + num2;
        printf("A soma de %d com %d e igual a %d \n", num1, num2, soma);
        return 0;
    */
}
