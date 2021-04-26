#include <stdio.h>
#include <stdlib.h>

/*  The typedef keyword creates a type definition that simplifies code
    and makes a program easier to read.
    typedef is commonly used with structures because it eliminates the
    need to use the keyword struct when declaring variables. */

typedef struct {
    char nome[256];
    float nota[3];
    float media;
} aluno; // The name of the struct comes here now

int main() {
    aluno a1; // structure tag is no longer used
    return 0;
}
