/*
 * Rules:
 * As partidas de Fastminton são jogadas sempre com dois jogadores (oponentes)
 * em uma quadra separada ao meio por uma rede;
 * Os jogadores são identificados pela sua posição no placar (jogador da
 * esquerda, jogador da direita);
 * Uma partida é composta por três games. Ganha quem alcançar dois games
 * primeiro;
 * Ganha o game quem alcançar ao menos 5 pontos e tiver uma diferença de ao
 * menos 2 pontos do oponente, ou o primeiro a chegar em 10 pontos;
 * O jogador da esquerda inicia sacando no primeiro game da partida; nos
 * demais, o jogador que inicia sacando é o que ganhou o último game;
 * Cada jogada resulta em um ponto, de quem sacou ou de quem recebeu o saque.
 * Quem ganhou o ponto irá sacar na próxima jogada.
 */

#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE *inputTests = fopen("./inputQ2-small.txt", "r");

    if (inputTests == NULL) {
        perror("Erro ao abrir o arquivo de testes!");
        exit(EXIT_FAILURE);
    }

    int GoalLeft = 0, GoalRight = 0;
    int PointsLeft = 0, PointsRight = 0;
    char leftPlayer = 'S', rightPlayer = 'R';

    char winner;
    char nextPlayer;

    char ch;
    while ((ch = fgetc(inputTests)) != EOF) {
        switch (ch) {
            case 'S': // Point to who did the serve
                PointsLeft++;
                break;
            case 'R': // Point to who received the serve
                PointsRight++;
                break;
            case 'Q': // Scoreboard announcement
                if (winner == leftPlayer) {
                    printf("%d(winner) - %d\n", GoalLeft, GoalRight);
                } else if (winner == rightPlayer) {
                    printf("%d - %d(winner)\n", GoalLeft, GoalRight);
                } else {
                    if (nextPlayer == leftPlayer)
                        printf("%d (%d*) - %d (%d)\n", GoalLeft, PointsLeft, GoalRight, PointsRight);
                    else
                        printf("%d (%d) - %d (%d*)\n", GoalLeft, PointsLeft, GoalRight, PointsRight);
                }

                nextPlayer = ch;
                break;
            case '\n': // End of the match
                if (nextPlayer == leftPlayer) {
                    printf("%d(winner) - %d\n", GoalLeft, GoalRight);
                } else if (nextPlayer == rightPlayer) {
                    printf("%d - %d(winner)\n", GoalLeft, GoalRight);
                }
                printf("\n");
                break;
        }

        if ((PointsLeft >= 5 && PointsLeft - PointsRight >= 2) || PointsLeft == 10) {
            GoalLeft++; // Game won by S
            PointsLeft = 0;
            PointsRight = 0;
            nextPlayer = 'S';
        } else if ((PointsRight >= 5 && PointsRight - PointsLeft >= 2) || PointsRight == 10) {
            GoalRight++; // Game won by R
            PointsLeft = 0;
            PointsRight = 0;
            nextPlayer = 'R';
        }

        // if (GoalLeft == 2) {
        //     PointsLeft = 0;
        //     PointsRight = 0;
        //     winner = leftPlayer;
        // } else if (GoalRight == 2) {
        //     PointsLeft = 0;
        //     PointsRight = 0;
        //     winner = rightPlayer;
        // }



    }

    fclose(inputTests);
    return 0;
}
