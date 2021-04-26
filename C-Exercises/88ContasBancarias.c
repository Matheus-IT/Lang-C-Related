#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
	int num;
	float saldo;
} Conta;

void limparBuffer() {
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

bool isInteger(char str[]) {
	int length = strlen(str);
	
	for (int i = 0; i < length; i++) {
		if (str[i] >= '0' && str[i] <= '9')
			continue;
		else
			return false;
	}
	return true;
}

bool isFloat(char str[]) {
	int length = strlen(str);
	
	for (int i = 0; i < length; i++) {
		if (str[i] == '.') {
			continue;
		} else {
			if (str[i] >= '0' && str[i] <= '9')
				continue;
			else
				return false;
		}
	}
	return true;
}

int lerInteiro(char msg[]) {
	char input[50];

	while (true) {
		printf("%s", msg);
		scanf(" %s", &input);
		limparBuffer();

		if (isInteger(input)) {
			return atoi(input);
		} else {
			printf("Invalid input! ");
		}
	}
}

float lerDecimal(char msg[]) {
	char input[50];

	while (true) {
		printf("%s", msg);
		scanf(" %s", &input);
		limparBuffer();

		if (isFloat(input)) {
			return atof(input);
		} else {
			printf("Invalid input! ");
		}
	}
}

Conta lerConta() {
	Conta c;
	
	c.num = lerInteiro("Informe o numero: ");
	c.saldo = lerDecimal("Informe o saldo.: ");

	return c;
}

void cadastrarConta(Conta contas[], int totCadastradas) {
	int posNovaConta = totCadastradas;
	contas[posNovaConta] = lerConta();
}

void mostrarContasCadastradas(Conta contas[], int totCadastradas) {
	for (int i = 0; i < totCadastradas; i++) {
		printf("%d Numero: %d \n", i+1, contas[i].num);
	}
	puts("-------------------------------");
}

void desenharLinha(int tamanho) {
	for (int i = 0; i < tamanho; i++) {
		printf("=");
	}
}

void mostrarCabecalho(char msg[]) {
	int tamanho3x = 3 * (strlen(msg)) + 2; // + 2 because of the space around the word
	int tamanho = strlen(msg);

	desenharLinha(tamanho3x);
	printf("\n");

	desenharLinha(tamanho);
	printf(" %s ", msg);
	desenharLinha(tamanho);

	printf("\n");
	desenharLinha(tamanho3x);
	printf("\n");
}

void mostrarContasCadastradasESaldo(Conta contas[], int totCadastradas) {
	for (int i = 0; i < totCadastradas; i++) {
		printf("%d Numero: %d Saldo: %.2f \n", i+1, contas[i].num, contas[i].saldo);
	}
	puts("-------------------------------");
}

void mostrarSaldo(Conta contas[], int totCadastradas, int numero) {
	for (int i = 0; i < totCadastradas; i++) {
		if (contas[i].num == numero) {
			printf("\n======================\n");
			puts("=== Saldo de Conta ===");
			printf("Numero: %d \n", contas[i].num);
			printf("Saldo: %.2f\n", contas[i].saldo);
			puts("======================");
			break;
		}
	}
}

void depositar(Conta *contas, int totCadastradas, int numero, float deposito) {
	for (int i = 0; i < totCadastradas; i++) {
		if (contas[i].num == numero) {
			contas[i].saldo += deposito;
			break;
		}
	}
}

void sacar(Conta *contas, int totCadastradas, int numero, float saque) {
	for (int i = 0; i < totCadastradas; i++) {
		if (contas[i].num == numero) {
			contas[i].saldo -= saque;
			break;
		}
	}
}

bool temUmaContaComEsseNumero(Conta contas[], int totCadastradas, int numero) {
	for (int i = 0; i < totCadastradas; i++) {
		if (contas[i].num == numero)
			return true;
	}
	return false;
}

void removerConta(int numero, Conta contas[], int totCadastradas) {
	for (int i = 0; i < totCadastradas; i++) {
		if (contas[i].num == numero) {
			for (int j = i; j < (totCadastradas - 1); j++) {
				contas[j] = contas[j + 1];
			}
		}
	}
}

int main() {
	Conta contas[MAX]; // solve this problem
	int totalDeContasCadastradas = 0;

	int opcao = 0;
	char msg[40] = "";
	do {
		system("cls");
		
		mostrarCabecalho("Controle de Contas Bancarias");

		printf(" Contas cadastradas %d \n", totalDeContasCadastradas);
		
		puts("1. Cadastrar Conta (ate 5 contas) 2. Mostrar Saldo");
		puts("3. Depositar em Conta             4. Sacar dinheiro");
		puts("5. Transferencia entre Contas     6. Mostrar Todas");
		puts("0. Sair                           7. Remover conta");

		printf(" - %s \n", msg);
		strcpy(msg, ""); // mostra cada mensagem uma única vez

		opcao = lerInteiro("Informe sua opcao: ");

		system("cls");
		switch (opcao) {
			case 1:
				if (totalDeContasCadastradas < MAX) {
					mostrarCabecalho("Cadastra nova conta");
					cadastrarConta(contas, totalDeContasCadastradas);
					
					totalDeContasCadastradas++;
					strcpy(msg, "Conta cadastrada com sucesso!");
				} else {
					strcpy(msg, "Total de contas atingido");
				}
				break;
			case 2:
				if (totalDeContasCadastradas > 0) {
					mostrarCabecalho("Mostrar Saldo");
					mostrarContasCadastradas(contas, totalDeContasCadastradas);

					int numero = 0;
					while (true) {
						numero = lerInteiro("Informe o numero da conta: ");

						if (temUmaContaComEsseNumero(contas, totalDeContasCadastradas, numero)) {
							break;
						} else {
							printf("Nao existe uma conta com esse numero \n");
						}
					}
					
					system("cls");
					mostrarSaldo(contas, totalDeContasCadastradas, numero);
					system("pause");
				} else {
					strcpy(msg, "Cadastre alguma conta primeiro");
				}
				break;
			case 3:
				if (totalDeContasCadastradas > 0) {
					mostrarCabecalho("Depositar em Conta");
					mostrarContasCadastradasESaldo(contas, totalDeContasCadastradas);

					int numero = 0;
					while (true) {
						numero = lerInteiro("Informe o numero da conta: ");

						if (temUmaContaComEsseNumero(contas, totalDeContasCadastradas, numero)) {
							break;
						} else {
							printf("Nao existe uma conta com esse numero \n");
						}
					}
					
					float deposito;
					deposito = lerDecimal("Informe o valor do deposito: ");

					depositar(contas, totalDeContasCadastradas, numero, deposito);
					strcpy(msg, "Valor depositado com sucesso!");
				} else {
					strcpy(msg, "Cadastre alguma conta primeiro");
				}
				break;
			case 4:
				if (totalDeContasCadastradas > 0) {
					mostrarCabecalho("Sacar dinheiro");
					mostrarContasCadastradasESaldo(contas, totalDeContasCadastradas);

					int numero = 0;
					while (true) {
						numero = lerInteiro("Informe o numero da conta: ");

						if (temUmaContaComEsseNumero(contas, totalDeContasCadastradas, numero)) {
							break;
						} else {
							printf("Nao existe uma conta com esse numero \n");
						}
					}

					float saque;
					saque = lerDecimal("Valor do saque: ");

					sacar(contas, totalDeContasCadastradas, numero, saque);
					strcpy(msg, "Valor sacado com sucesso!");
				} else {
					strcpy(msg, "Cadastre alguma conta primeiro");
				}
				break;
			case 5:
				if (totalDeContasCadastradas >= 2) {
					mostrarCabecalho("Transferencia entre Contas");
					mostrarContasCadastradasESaldo(contas, totalDeContasCadastradas);

					int numeroContaOrigem = 0;
					while (true) {
						numeroContaOrigem = lerInteiro("Informe o numero da conta de origem...: ");

						if (temUmaContaComEsseNumero(contas, totalDeContasCadastradas, numeroContaOrigem)) {
							break;
						} else {
							printf("Nao existe uma conta com esse numero \n");
						}
					}
					
					int numeroContaDestino = 0;
					while (true) {
						numeroContaDestino = lerInteiro("Informe o numero da conta de destino...: ");

						if (temUmaContaComEsseNumero(contas, totalDeContasCadastradas, numeroContaDestino)) {
							break;
						} else {
							printf("Nao existe uma conta com esse numero \n");
						}
					}
					
					float valTransferir = 0;
					valTransferir = lerDecimal("Informe o valor a transferir: ");

					sacar(contas, totalDeContasCadastradas, numeroContaOrigem, valTransferir);
					depositar(contas, totalDeContasCadastradas, numeroContaDestino, valTransferir);

					strcpy(msg, "Transferencia realizada com sucesso!");
				} else {
					strcpy(msg, "Cadastre as contas primeiro, pelo menos duas");
				}
				break;
			case 6:
				if (totalDeContasCadastradas > 0) {
					mostrarCabecalho("Todas as contas");
					mostrarContasCadastradasESaldo(contas, totalDeContasCadastradas);
					system("pause");
				} else {
					strcpy(msg, "Cadastre alguma conta primeiro");
				}
				break;
			case 7:
				if (totalDeContasCadastradas > 0) {
					mostrarCabecalho("Remover conta");
					mostrarContasCadastradas(contas, totalDeContasCadastradas);
					
					int numero;
					while (true) {
						numero = lerInteiro("Insira o numero da conta: ");

						if (temUmaContaComEsseNumero(contas, totalDeContasCadastradas, numero)) {
							break;
						} else {
							printf("Nao existe uma conta com esse numero \n");
						}
					}
					
					removerConta(numero, contas, totalDeContasCadastradas);
					totalDeContasCadastradas--;
					strcpy(msg, "Conta removida com sucesso");
				} else {
					strcpy(msg, "Cadastre alguma conta primeiro");
				}
				break;
			case 0:
				puts("Obrigado, volte sempre");
				break;
			default:
				strcpy(msg, "Opcao invalida!");
		}
	} while(opcao != 0);
	system("pause");
	return 0;
}
