#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char input[40];

    printf(" - Digite uma frase (max 40): ");
    fgets(input, 40, stdin);

    char *frase;
    frase = (char *)(malloc(strlen(input) * sizeof(char)));

    strcpy(frase, input);
    
    input[0] = '\0';

    printf(" - Frase: %s \n", frase);
    free(frase);
    return 0;
}
