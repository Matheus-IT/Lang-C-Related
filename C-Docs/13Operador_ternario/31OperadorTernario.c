#include <stdio.h>
#include <stdlib.h>


int main(){
    float dinheiro;

    printf("\nQuanto de dinheiro eu tenho? ");
    scanf("%f", &dinheiro);
    // "if (something is True) ? {do this} :(else) {do this}"
    (dinheiro > 10000) ? printf("Eu vou pra disney!! :D") : printf("#Chateado :C");
    return 0;
}
