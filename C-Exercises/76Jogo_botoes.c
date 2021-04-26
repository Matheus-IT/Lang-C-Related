#include <stdio.h>
#include <stdlib.h>

int main() {
	int teams = 0, matches = 0, possible_points = 0, total_points = 0, draws = 0;
	char name = '\0';

	printf("\n ====== Copa do Mundo de futebol de botoes ====== \n");
	printf(" - Quantos times? \n >> ");
	scanf(" %d", &teams);
	while (teams < 0 || teams > 200) {
		printf(" - Entrada invalida! Quantos times? \n >> ");
		scanf(" %d", &teams);
	}
	printf(" - Quantas partidas? \n >> ");
	scanf(" %d", &matches);
	while (matches < 0 || matches > 10000) {
		printf(" - Enatrada invalida! Quantas partidas? \n >> ");
		scanf(" %d", &matches);
	}

	if (!(teams && matches)) { 
		printf(" - Execucao terminada pelo input... \n");
		exit(1);
	}
	
	possible_points = matches * 3;

	for (int c = 0, name = 'A'; c < teams; c++) {
		int points;

		printf(" - Time %c marcou: ", name);
		scanf(" %d", &points);
		total_points += points;
		name++;
	}
	draws = possible_points - total_points;
	printf(" Empates: %d", draws);
	return 0;
}
