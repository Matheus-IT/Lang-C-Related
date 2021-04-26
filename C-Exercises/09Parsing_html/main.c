#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int extractTags(char string[]) {
	char ch;
	char stringAux[256] = "";

	int j = 0;
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == '\n')
			continue;
		if (string[i] == '<') {
			while(string[i] != '>')
				i++;
		} else
			stringAux[j++] = string[i];
	}
	strcpy(string, stringAux);
	return j; // the length of our new string
}

int main() {
	char inputFileName[] = ".\\pag1.html";
	char outputFileName[] = ".\\arquivoDeSaida.html";

	FILE *f1 = fopen(inputFileName, "r");
	FILE *f2 = fopen(outputFileName, "w");

	char string[256];

	while(fgets(string, 256, f1)) {
		if (extractTags(string)) {
			fprintf(f2, "%s\n", string);
		}
	}

	puts("Pronto, agora e so conferir o arquivo de saida");

	fclose(f1);
	fclose(f2);
	return 0;
}
