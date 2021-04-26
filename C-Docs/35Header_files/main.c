#include <stdio.h>
#include <stdlib.h>

/*  If a file needs something that's inside another, the one who
    needs will come bellow:
    Ex:
    #include "second.h"
    #include "first.h" -> This guy needs something inside "second.h"
*/
#include "functions.h" 

int main() {
    int n, r;

    printf("Type a number: ");
    scanf(" %d", &n);
    r = calcFact(n); //This function came from "functions.c"
    printf(" - Result %d \n", r);
    return 0;
}
