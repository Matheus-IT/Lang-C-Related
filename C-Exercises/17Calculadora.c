#include <stdio.h>
#include <stdlib.h>


int main(){
    int op, num1, num2, soma, sub, multi, div;
    op = 0;
    printf("\n============= PROGRAMA CALCULADORA =============\n");
    printf("Digite o primeiro valor: ");
    scanf("%d", &num1);
    printf("Digite o segundo valor: ");
    scanf("%d", &num2);

    while (op != 6)
    {   
        printf("==============================================\n");
        printf("[%d] - [%d] \n", num1, num2);
        printf("Qual a operacao que voce quer fazer com eles? \n");
        printf("[1]SOMA \n");
        printf("[2]SUBTRACAO \n");
        printf("[3]MULTIPLICACAO \n");
        printf("[4]DIVISAO \n");
        printf("[5]DIGITAR OUTROS VALORES\n");
        printf("[6]SAIR DO PROGRAMA \n");
        printf("=>> ");
        scanf("%d", &op); //Escolher qual operação fazer com num1 e num2
        while ((op != 1) && (op != 2) && (op != 3) && (op != 4) && (op != 5) && (op != 6))
        {
            printf("Erro! Digite um dos valores acima! \n");
            printf("=>> ");
            scanf("%d", &op);
        }
        system("cls");
        printf("==============================================\n");
        switch (op)
        {
        case 1: //Somar os valores
            soma = num1 + num2;
            printf("A SOMA de %d com %d e igual a %d \n", num1, num2, soma);
            break;
        case 2: //Subtrair
            sub = num1 - num2;
            printf("%d menos %d e igual a %d \n", num1, num2, sub);
            break;
        case 3: //Multiplicar
            multi = num1 * num2;
            printf("%d vezes %d e igual a %d \n", num1, num2, multi);
            break;
        case 4: //Dividir
            div = num1 / num2;
            printf("%d dividido por %d e igual a %d \n", num1, num2, div);
            break;
        case 5:
            printf("Digite o primeiro valor: ");
            scanf("%d", &num1);
            printf("Digite o segundo valor: ");
            scanf("%d", &num2);
        }
    }
    printf("Tchau... :)");
    return 0;
}
