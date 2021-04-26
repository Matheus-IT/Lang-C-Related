#include <stdio.h>


int main(){
    char a[40];
    printf("Digite o seu nome: ");
    scanf("%s", &a); // -> Vai pegar so o PRIMEIRO nome
    printf("Ola %s, prazer em conhece-lo", a);
    return 0;
}
