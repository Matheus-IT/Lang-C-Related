#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[40];
    int n_matricula;
    char curso[40];
} aluno;

void mostrar_dados(aluno alunos[]) {
    for (int count = 0; count < 3; count++) {
        printf(" === Aluno %s ===\n", alunos[count].nome);
        printf(" - N da matricula %d \n", alunos[count].n_matricula);
        printf(" - Curso %s \n", alunos[count].curso);
    }
}

void remove_salto(char n[]) { //Funcao para remover o \n do final da string
    int length = strlen(n)-1;
    n[length] = '\0';
}

int main() {
    aluno alunos[3];

    for (int count = 0; count < 3; count++) {
        printf(" === Aluno %d ===\n", count+1);
        setbuf(stdin, NULL);
        printf(" - Digite seu nome: ");
        fgets(alunos[count].nome, 40, stdin);
        remove_salto(alunos[count].nome); //Remove o \n do final
        printf(" - Insira o numero da matricula: ");
        scanf(" %d", &alunos[count].n_matricula);
        setbuf(stdin, NULL);
        printf(" - Digite o curso: ");
        fgets(alunos[count].curso, 40, stdin);
    }
    mostrar_dados(alunos);
    return 0;
}
