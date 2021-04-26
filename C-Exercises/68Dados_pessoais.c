#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[40];
    int idade;
    union {
        long int cep;
        char cidade[40];
    } endereco;
} cadastro;

int main() {
    cadastro pessoa;
    int op;

    setbuf(stdin, NULL);
    printf(" - Digite seu nome: ");
    fgets(pessoa.nome, 40, stdin);
    printf(" - Digite sua idade: ");
    scanf(" %d", &pessoa.idade);
    printf(" - Tipo de endereco: \n [1] cep \n [2] cidade \n escolha: ");
    scanf(" %d", &op);
    if (op == 1) {
        printf(" - Digite seu cep: ");
        scanf(" %d", &pessoa.endereco.cep);
    } else {
        setbuf(stdin, NULL);
        printf(" - Digite a cidade: ");
        fgets(pessoa.endereco.cidade, 40, stdin);
    }
    return 0;
}
