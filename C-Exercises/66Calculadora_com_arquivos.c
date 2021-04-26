#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "66funcoes.c"


int main(){
    float n1 = 0, n2 = 0, resultado = 0;
    int op = 0;
    char operacao = ' ';
    bool mostra_resultado = false;

    printf("========== CALCULADORA ==========\n");
    FILE *valores;
    valores = fopen("66num.txt", "r"); //Abrir modo de leitura
    if (valores != NULL){
        fscanf(valores, " %f %f", &n1, &n2);
    }else{
        inserir_numeros(&n1, &n2, &mostra_resultado);
    }
    while (op != 6){ //op == 6 sai do programa
        menu_opcoes(n1, n2, &op, &operacao, &resultado, &mostra_resultado); //Mostrar menu com opcoes
        escolher(&n1, &n2, &resultado, &operacao, &op, &mostra_resultado); //Escolher qual opcao executar
        if (op == 6) //Sai do programa
            saindo_programa(n1, n2, &op, valores);
    }
    return 0;
}
