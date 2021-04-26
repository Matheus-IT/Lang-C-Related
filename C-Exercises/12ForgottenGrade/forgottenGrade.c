#include <stdio.h>
#include <math.h>

int main() {
	int nota1, media;

	scanf("%d", &nota1);
	scanf("%d", &media);

	int nota2 = 1, resultado = 0;
	while (resultado != media) {
		resultado = ceil((float) (nota1 + nota2) / 2);
		nota2++;
	}
	printf("%d", nota2);
	return 0;
}
