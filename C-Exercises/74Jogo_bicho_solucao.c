#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int m, n; 
    float v, p = 0;

    m = 213929;

    printf(" Digite V e N: ");
    scanf(" %f %d", &v, &n);

    if (n % 10000 == m % 10000) {
		p = v * 3000;
	} else if (n % 1000 == m % 1000) {
		p = v * 500;
	} else if (n % 100 == m % 100) {
		p = v * 50;
	} else {
        n = n % 100;
        m = m % 100;


        while (n % 4 != 0) n++;
        while (m % 4 != 0) m++;

        // Solução dos meninos:
		//int group_n = ((n % 100) - 1) / 4;
		//int group_m = ((m % 100) - 1) / 4;

        n = (n == 0) ? (100 - 1) / 4 : (n - 1) / 4;
        m = (m == 0) ? (100 - 1) / 4 : (m - 1) / 4;
        
		if (n == m) {
			p = v * 16;
		} else {
			printf("Infelizmente não foi dessa vez");
		}
	} 
	if (p > 0) printf("Parabens voce ganhou R$%.2f", p);
	return 0;
}
