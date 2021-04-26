#include <stdio.h>
#include <stdlib.h>
#include "functions.h" //We have to place this guy here!

//Here we place what we'll use inside this file to perform the operations
int calcFact(int n) {
    if (n == 1) return 1;
    return n * calcFact(n - 1);
}
