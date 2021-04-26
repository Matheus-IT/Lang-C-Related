#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	/* Function fopen("nome_do_arquivo.txt", <Mode>)
		- r open for reading (file must exist)
		- w open for writing (file need not exist)
		- a open for append (file need not exist)
		- r+ open for reading and writing from beginning
		- w+ open for reading and writing, overwriting file
		- a+ open for reading and writing, appending to file

		------------- Functions to Read from a File -------------

		- fgetc(fp) Returns the next character from the file pointed to by fp. If the end of the file has 
		been reached, then EOF is returned.

		- fgets(buff, n, fp) Reads n-1 characters from the file pointed to by fp and stores the string in 
		buff.

		- A NULL character '\0' is appended as the last character in buff. If fgets encounters a newline
		character or the end of file before n-1 characters is reached, then only the characters up to that
		point are stored in buff.

		- fscanf(fp, conversion_specifiers, vars) Reads characters from the file pointed to by fp and 
		assigns input to a list of variable pointers vars using conversion_specifiers. As with scanf,
		fscanf stops reading a string when a space or newline is encountered. */

	/* -------------------------- Reading Strings From Files -------------------------- */

	FILE *f1 = NULL;
	char fileName[12] = "Strings.txt";
	f1 = fopen(fileName, "r");
	
	if (f1 == NULL) {
		printf(" - O arquivo %s nao pode ser aberto! \n", fileName);
		exit(1);
	}

	char phrase[101];
	puts("O que esta dentro de String.txt:");
	while (fgets(phrase, 100, f1) != NULL) {
		printf("    %s", phrase);
	}
	printf("\n");

	fclose(f1);

	/* -------------------------- Reading Numbers From Files -------------------------- */

	FILE *f2 = NULL;
	strcpy(fileName, "Numeros.txt");
	f2 = fopen(fileName, "r");

	if (f2 == NULL) {
		printf(" - O arquivo %s nao pode ser aberto! \n", fileName);
		exit(-1);
	}

	int nums[3];
	fscanf(f2, " %d %d %d", &nums[0], &nums[1], &nums[2]);
	printf("O que esta dentro de Numero: \n    %d %d %d \n", nums[0], nums[1], nums[2]);

	fclose(f2);

	return 0;
}
