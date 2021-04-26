#include <stdio.h>
#include <math.h>

int main() {
	int capacidade, alunos;
	
	scanf("%d", &capacidade);
	scanf("%d", &alunos);
		
	int viagens = alunos / capacidade;
	int monitores = viagens;

	int viagensComMonitores = ceil((float) (alunos + monitores) / capacidade);

	printf("%d", viagensComMonitores);
	return 0;
}
