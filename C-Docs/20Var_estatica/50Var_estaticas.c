#include <stdio.h>
#include <stdlib.h>

/* VARIAVEL ESTATICA tem escopo local, mas nao e destruida quando
   sai da funcao, ela retem o valor e pode ser acessada toda vez
   que a funcao e chamada no programa*/

void say_hello() {
  static int nChamadas = 1; //Variavel estatica

  printf("Hello number %d\n", nChamadas);
  nChamadas++;
}


int main()
{
    int i;

    for (i = 0; i < 5; i++)
    {
        say_hello();
    }
    return 0;
}
