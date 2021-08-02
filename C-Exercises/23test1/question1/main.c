/*
 * Grid 10x10
 * Rules: Dada a lista dos navios e suas posições, você deve determinar se o
 * posicionamento inicial é válido.
 * ---------------------------------------------------------------------------
 * Para cada um dos casos de teste no arquivo, a primeira linha da entrada
 * contém um valor inteiro N (1 ≤ N ≤ 100), indicando o número de navios. Cada
 * uma das próximas N linhas contém quatro inteiros:
 * D, L, R e C com D ∈ {0, 1}, 1 ≤ L ≤ 5 e 1 ≤ R, C ≤ 10 descrevendo um navio.
 * Se D = 0 então o navio está alinhado horizontalmente, e ocupa as posições:
 * (R, C)...(R, C + L – 1). Do contrário, o navio está alinhado verticalmente,
 * e ocupa as posições (R, C) ... (R + L – 1, C).
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_POSITIONS 100 // The table is a 10 x 10

typedef struct {

} Position;


int main() {
    FILE *inputTests = fopen("./inputQ1.txt", "r");

    if (inputTests == NULL) {
        perror("Erro ao abrir o arquivo de testes!");
        exit(EXIT_FAILURE);
    }

    int numOfShips = 0;
    Position *positionsOccupied = malloc(MAX_POSITIONS * sizeof(Position));
    // Read until the end of the file
    while (fscanf(inputTests, "%d", &numOfShips) == 1) {
        printf("Number of ships: %d\n", numOfShips);

        for (int i = 0; i < numOfShips; i++) {
            int direction = 0, length = 0, rowStart = 0, columnStart = 0;

            fscanf(inputTests, "%d %d %d %d", &direction,
                                              &length,
                                              &rowStart,
                                              &columnStart);

            // Testing limits
            if ((direction < 0 || direction > 1) ||   // Invalid direction
                (length < 1 || length > 5) ||         // Invalid length
                (rowStart < 1 || rowStart > 10) ||    // Invalid row start
                (columnStart < 1 || columnStart > 10) // Invalid column start
                ) {
                perror("Erro: dado de entrada invalido ou fora do limite!");
            }

            printf("\n%d %d %d %d\n", direction, length, rowStart, columnStart);

            int currentRow = rowStart;
            int currentColumn = columnStart;

            for (int c = 0; c < length; c++) {
                if (direction == 0) { // Ship is horizontally
                    // Need to finish
                    positionsOccupied = createPosition(currentRow, currentColumn);
                    currentColumn++;
                } else if (direction == 1) { // Ship is vertically
                    currentRow++;
                } else {
                    perror("Erro ao avaliar direcao!");
                    exit(EXIT_FAILURE);
                }
            }

            puts("N");
            puts("Y");
        }
    }

    fclose(inputTests);
    return 0;
}