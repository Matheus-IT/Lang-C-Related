#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
	Aluno: Matheus da Costa da Silva
	Matricula: 1074819
*/

void createAnimals(char animals[25][4][3]) {
	char n_string[5];
	int n = 1;
	
	for (int i = 0; i < 25; i++) { 	// qtt groups
		for (int j = 0; j < 4; j++) {	// qtt numb per group
			if (i == 24 && j == 3) {
				strcpy(animals[i][j], "00");
			} else {
				itoa(n, n_string, 10); // int to string in decimal
				strcpy(animals[i][j], n_string);
			}
			n++;
		}
	}
}

char * readPlayNum(char msg[]) {
	int n = 0;
	char *n_string = (char *) malloc(10 * sizeof(char));
	
	printf(msg);
	scanf(" %d", &n);
	while (n < 0 || n > 1000000) {
		printf(" - Entrada invalida! \n");
		printf(msg);
		scanf(" %d", &n);
	}
	itoa(n, n_string, 10); // int to string in decimal
	return n_string;
}

char * putZeros(char *n_string) {
	char zeros[10];

	if (strlen(n_string) < 4) {
		if (strlen(n_string) < 2) {
			strcpy(zeros, "000");
		} else if (strlen(n_string) < 3) {
			strcpy(zeros, "00");
		} else if (strlen(n_string) < 4) {
			strcpy(zeros, "0");
		}
		strcpy(n_string, strcat(zeros, n_string)); // put zeros in front of the number
	}
	return n_string;
}

char unidade(char *n_string) {
	int length = strlen(n_string);
	return n_string[length - 1];
}

char dezena(char *n_string) {
	int length = strlen(n_string);
	return n_string[length - 2];
}

char centena(char *n_string) {
	int length = strlen(n_string);
	return (n_string[length - 3]);
}

char milhar(char *n_string) {
	int length = strlen(n_string);
	return (n_string[length - 4]);
}

int animal(char animals[25][4][3], char *n_string) {
	for (int i = 0; i < 25; i++) { 	// qtt groups
		for (int j = 0; j < 4; j++) {	// qtt numb per group
			if (
				dezena(animals[i][j]) == dezena(n_string) &&
				unidade(animals[i][j]) == unidade(n_string)
				) {
				return i+1;
			}
		}
	}
}

float evaluateThePrice(char animals[25][4][3], char *play_num, char *number_drawn, float bet) {
	if (
		milhar(play_num) == milhar(number_drawn) &&
		centena(play_num) == centena(number_drawn) &&
		dezena(play_num) == dezena(number_drawn) &&
		unidade(play_num) == unidade(number_drawn)
		) {
		return bet * 3000;
	} else if (
		centena(play_num) == centena(number_drawn) &&
		dezena(play_num) == dezena(number_drawn) &&
		unidade(play_num) == unidade(number_drawn)
		) {
		return bet * 500;
	} else if (
		dezena(play_num) == dezena(number_drawn) &&
		unidade(play_num) == unidade(number_drawn)
		) {
		return bet * 50;
	} else if (animal(animals, play_num) == animal(animals, number_drawn)) {
		return bet * 16;
	} else {
		return bet * 0;
	}
}

int main() {
	char animals[25][4][3];
	float bet = 0.0, price = 0.0;
	char play_num[10], number_drawn[10];
	
	createAnimals(animals);
	
	printf(" = FAZER APOSTA = \n");
	printf(" - Sua aposta R$: ");
	scanf(" %f", &bet);

	strcpy(play_num, readPlayNum(" - Um numero no intervalo de 0 a 1000000: "));
	// put zeros in front of play_num, if needed:
	strcpy(play_num, putZeros(play_num));
	printf("n = %s \n", play_num);

	//srand(time(NULL));
	//number_drawn = rand() % 1000001; // a number between 0 and 1000000
	strcpy(number_drawn, putZeros("0000")); // pode colocar o m manualmente aqui, se não for necessário o n random
	printf("m = %s \n", number_drawn);

	price = evaluateThePrice(animals, play_num, number_drawn, bet);
	printf("Jogador ganhou: %.2f \n", price);
	return 0;
}
