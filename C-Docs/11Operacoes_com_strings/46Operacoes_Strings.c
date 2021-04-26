#include <stdio.h>
#include <stdlib.h>
#include <string.h>

_Bool stringIgual(char s1[], char s2[]);

int main()
{   
    char msg1[30];
    char msg2[30];

    printf(" - Digite uma mensagem: ");
    fflush(stdin);
    gets(msg1);
    printf(" - Digite outra mensagem: ");
    fflush(stdin);
    gets(msg2);
    /*
        #Include <string.h> to use:
        strlen() - get length of a string
        strcat() - merge two strings
        strcpy() - copy one string to another
        strlwr() - convert string to lower case
        strupr() - conver string to upper case
        strrev() - reverse string
        strcmp() - compare two strings 
    */
    if (stringIgual(msg1, msg2))
    {
        printf("correto");
    }
    else
    {
        printf("nao e igual");
    }
    return 0;
}


_Bool stringIgual(char s1[], char s2[])
{
    int cont = 0;
    do
    {
        if (s1[cont] != s2[cont])
        {
            return 0;
        }
        cont++;
    } while ((s1[cont] == s2[cont]) && (s1[cont] != '\0') && (s2[cont] != '\0'));
    return 1;
}
