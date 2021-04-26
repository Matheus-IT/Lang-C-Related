#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41 // the maximum amount of characters

void clearBuffer() {
	char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void getStr(char str[]) {
	fgets(str, MAX, stdin);
	str[strlen(str) - 1] = '\0'; // take the \n out
}

void rearrangeScoreboard(char players[][MAX], int score[], const int length) {
	for (int i = 1; i < length; i++) {
		for (int j = 0; j < i; j++) {
			if (score[i] > score[j]) {
				int auxScore = score[i];
				score[i] = score[j];
				score[j] = auxScore;

				char auxPlayer[MAX];
				strcpy(auxPlayer, players[i]);
				strcpy(players[i], players[j]);
				strcpy(players[j], auxPlayer);
			}
		}
	}
}

void showScoreboard(char players[][MAX], int score[], const int length) {
	rearrangeScoreboard(players, score, length);
	printf(" ========== SCOREBOARD ========== \n");
	for (int i = 0; i < length; i++) {
		printf(" - %d %s - %d points \n", i+1, players[i], score[i]);
	}
}



int main() {
	const int length = 10;
	char players[length][MAX];
	int score[length];

	for (int i = 0; i < 10; i++) {
		printf(" - Type the %do player's name: ", i+1);
		getStr(players[i]);
		printf(" - What the score of %s? ", players[i]);
		scanf(" %d", &score[i]);
		clearBuffer();
	}
	
	showScoreboard(players, score, length);
	return 0;
}
