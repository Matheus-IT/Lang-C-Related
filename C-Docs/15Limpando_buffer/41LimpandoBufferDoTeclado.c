#include <stdio.h>
#include <stdlib.h>


int limpando_buffer() { //Funcao criada para LIMPAR O BUFFER do teclado
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    return 0;
}


int main() {
    char a, b, c;

    printf(" - Digite tres letras: ");
    a = getchar();
    limpando_buffer();
    b = getchar();
    limpando_buffer();
    c = getchar();
    limpando_buffer();
    printf(" - A = %c\n", a);
    printf(" - B = %c\n", b);
    printf(" - C = %c\n", c);
    return 0;
}
