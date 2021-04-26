#include <stdio.h>
#include <stdlib.h>


void* square (const void *num) {
  int *result = NULL;
  result = (*(int *)num) * (*(int *)num);
  return result;
}


int main()
{
    /*
    Void pointers are often used for function declarations.
    For example: void * square (const void *); 
    Using a void * return type allows for any return type. Similarly, PARAMETERS that are void * accept any ARGUMENT type. If you want to use the data passed in by the parameter without changing it, you declare it  const.

    You can leave out the parameter name to further insulate the declaration from its implementation. Declaring a function this way allows the definition to be customized as needed without having to change the declaration.
    */

    int x, sq_int;
    x = 6;
    sq_int = square(&x);
    printf("%d squared is %d\n", x, sq_int);

    return 0;
}
