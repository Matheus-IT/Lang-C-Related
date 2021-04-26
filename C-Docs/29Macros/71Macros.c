#include <stdio.h>
#include <stdlib.h>
#define pi 3.14159
#define double_pi 2 * pi
#define area_triangulo(base, altura) (float)(base * altura)/2
#define maior(n1, n2) n1 > n2 ? n1 : n2
#define letra(l) l >= 'A' && l <= 'Z'



int main()
{
    printf(" %f \n", pi);
    printf(" %f \n", double_pi);
    printf(" - Area do triangulo %4.2f \n", area_triangulo(5, 9));
    printf(" - Quem e maior %d \n", maior(5, 9));
    printf(" - Letra maiuscula? %d", letra('b'));
    return 0;
}
