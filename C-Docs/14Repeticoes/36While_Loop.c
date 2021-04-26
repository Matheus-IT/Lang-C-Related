#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


int main(){
    int n = 0;

    system("cls");
    while (n < 10)
    {
        printf("%d \n", n+1);
        n++;
        Sleep(500);
    }
    printf("Terminei de contar! \n");
    return 0;
}
