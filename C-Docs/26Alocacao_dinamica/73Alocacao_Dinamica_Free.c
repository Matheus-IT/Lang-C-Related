#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int *p = NULL;

    p = (int *)(malloc(sizeof(int)));
    p = (int *)1500;
    free(p);
    printf(" %d", p); //Even though this guy was free it's goin' to show the value within it
    return 0;
}
