#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>


int main()
{
    char password[30] = "";
    char confirm[30] = "";

    system("cls");
    printf(" - Type a password (max 30 caracters): ");
    fflush(stdin);
    gets(password);
    printf(" - Your password is saved! \n");
    Sleep(2000);
    printf(" - Type your password (max 30 caracters): ");
    gets(confirm);
    if (!strcmp(confirm, password))
    {
        printf(" - Password correct! \n");
    }
    else
    {
        printf(" - Incorrect password! \n");
    }
    return 0;
}
