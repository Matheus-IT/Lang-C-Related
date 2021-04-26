#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_ARQ "nomes.bin"
#define SIM 1
#define NAO 0

struct Aluno {
	unsigned apagado;
	unsigned mat;
	float nota;
	char nome[10];
};

void mostrar () {
	struct Aluno a;
	FILE *fp = NULL;
		
	if (fp = fopen(NOME_ARQ, "rb")) {
		while (fread(&a, sizeof(struct Aluno), 1, fp) == 1) {
			if (!a.apagado) {
				printf("\nAluno: %u - %s", a.mat, a.nome);
				printf("\nNota.: %.2f\n", a.nota);
			}
		}
		fclose(fp);
	} else { 
		printf("Erro ao abrir arquivo!\n");
	}
}

void cadastrar () {
	struct Aluno a;
	FILE *fp = NULL;
	
	a.apagado = NAO;

	printf("Informe a matricula e a nota: ");
	scanf("%u %f", &a.mat, &a.nota); 
	printf("Informe seu nome: ");	
	scanf(" %10[^\n]", a.nome);
	
	if (fp = fopen(NOME_ARQ, "ab")) {
		if(fwrite(&a, sizeof(struct Aluno), 1, fp) == 1)
			printf("Dado gravado com sucesso!\n");
		else
			printf("Erro ao gravar dado!\n");
		fclose(fp);
	} else if (fp = fopen(NOME_ARQ, "wb")) {
		if(fwrite(&a, sizeof(struct Aluno), 1, fp) == 1)
			printf("Dado gravado com sucesso!\n");
		else
			printf("Erro ao gravar dado!\n");
		fclose(fp);
	} else {
			printf("Erro ao criar/abrir arquivo!\n");
	}
}

void alterar () {
	struct Aluno a, chave;
	FILE *fp = NULL;
	long tam = sizeof(struct Aluno);
	
	printf("Informe a matricula e a nota: ");
	scanf("%u %f", &chave.mat, &chave.nota);
	
	if (fp = fopen(NOME_ARQ, "r+b")) {
		while(fread(&a, tam, 1, fp) == 1) {
			printf("Lido aluno: %u\n", a.mat);
			
			if (a.mat == chave.mat && !a.apagado) {
				a.nota = chave.nota;
				fseek(fp, -1 * tam, SEEK_CUR);
				if (fwrite(&a, tam, 1, fp) == 1) {
					puts("Dado alterado!!\n");
					break;
				} else {
					puts("Erro ao alterar!!\n");
				}
			}
		}
		fclose(fp);
	} else {
		puts("Erro ao abrir arquivo.\n");
	}
}

void remover() {
	struct Aluno a, chave;
	FILE *fp = NULL;
	long tam = sizeof(struct Aluno);
	
	printf("Informe a matricula: ");
	scanf(" %u", &chave.mat);
	
	if (fp = fopen(NOME_ARQ, "r+b")) {
		while(fread(&a, tam, 1, fp) == 1) {			
			if (a.mat == chave.mat && !a.apagado) {
				a.apagado = SIM;
				fseek(fp, -1 * tam, SEEK_CUR);
				if (fwrite(&a, tam, 1, fp) == 1) {
					puts("Dado apagado!!\n");
					break;
				} else {
					puts("Erro ao apagar!!\n");
				}
			}
		}
		fclose(fp);
	} else {
		puts("Erro ao abrir arquivo.\n");
	}
}

int main() {
	int opcao;
	do {
		puts("");
		puts("1. Cadastrar          2. Mostrar Todos");
		puts("3. Alterar            4. Apagar");   
		puts("0. Sair do programa");
		printf("Selecione sua opcao: ");
		scanf("%u", &opcao);
		switch(opcao) {
			case 1:
				cadastrar();
				break;
			case 2:
				mostrar();
				break;
			case 3:
				alterar();
				break;
			case 4:
				remover();
				break;
			case 0:
				break;
			default: puts("Opcao invalida!!");
	   	}
	} while(opcao != 0);
	 
	return(0);
}