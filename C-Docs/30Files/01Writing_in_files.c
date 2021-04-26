#include <stdio.h>
#include <stdlib.h>


int main() {
	/* Function: fopen("nome_do_arquivo.txt", <Mode>)
		- r open for reading (file must exist)
		- w open for writing (file need not exist)
		- a open for append (file need not exist)
		- r+ open for reading and writing from beginning
		- w+ open for reading and writing, overwriting file
		- a+ open for reading and writing, appending to file */

	FILE *f1;
	f1 = fopen("arquivo_texto.txt", "w");
	fprintf(f1, "Eu sou uma frase");
	fclose(f1);
	return 0;
}
