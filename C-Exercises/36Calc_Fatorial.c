#include <stdio.h>
#include <stdlib.h>


int calc_fact(int val) {
    int fat = 1;
    for (; val > 0; val--)
    {   
        fat *= val;
    }
    return fat;
}


int main() {   
    system("cls");

    long int result = calc_fact(4);
   
    printf(" %d \n", result);
    return 0;
}
