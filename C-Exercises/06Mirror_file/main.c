#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void saveInverted(char *inputFileName, FILE *outputFile) {
	FILE *file = fopen(inputFileName, "r");

	if (file) {
		char string[256];

		while (fgets(string, 256, file) != NULL) {
			
			for (int i = strlen(string); i >= 0; i--) {
				fputc(string[i], outputFile);
				printf("%c", string[i]);
			}
			fprintf(outputFile, "%c", '\n');
		}
	} else {
		puts("erro ao abrir arquivo");
	}

	fclose(file);
}

int main() {
	char inputFileName[31];
	char outputFileName[31];

	printf(" - Digite o nome do arquivo de entrada: ");
	scanf(" %s", &inputFileName);

	printf(" - Digite o nome do arquivo de saida: ");
	scanf(" %s", &outputFileName);
	
	FILE *inputFile = fopen(strcat(inputFileName, ".txt"), "w");
	FILE *outputFile = fopen(strcat(outputFileName, ".txt"), "w");

	if (inputFile && outputFile)
		printf("\nArquivos %s e %s criados com sucesso! \n", inputFileName, outputFileName);
	else {
		puts("Erro ao abrir os arquivos");
		return 1;
	}

	puts("\nEscreva o conteudo do arquivo de entrada ($ + Enter = parar):");
	char ch;
	do {
		ch = getchar();
		
		if (ch != '$')
			fputc(ch, inputFile);
	} while(ch != '$');

	puts("Ok os dados estao gravados!");
	puts("agora vou inverter o arquivo...");
	Sleep(4000);
	puts("Ok!");

	fclose(inputFile);
	saveInverted(inputFileName, outputFile);

	fclose(outputFile);
	return 0;
}
