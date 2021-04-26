#include <stdio.h>
#include <stdlib.h>


char * teste() //This function are returning a pointer
{
    static char r[] =  "Eu sou uma string\n";
    return(r);
}

int main()
{
    char *variavel;
    variavel = teste();
    printf("%s", variavel);
    return 0;
}
