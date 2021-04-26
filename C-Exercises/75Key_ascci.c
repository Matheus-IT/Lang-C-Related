#include <stdio.h>
#include <stdlib.h>

#define ESC 27

int main() {
    char key;
    
    do {
        printf(">>");
        scanf(" %c", &key);
        printf(" %c, %d \n", key, key);
    } while(key != '$');
    return 0;
}
