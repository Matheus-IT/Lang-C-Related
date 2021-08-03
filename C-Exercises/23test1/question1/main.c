/*
 * Grid 10x10
 * Rules: Dada a lista dos navios e suas posições, você deve determinar se o
 * posicionamento inicial é válido.
 * ---------------------------------------------------------------------------
 * Para cada um dos casos de teste no arquivo, a primeira linha da entrada
 * contém um valor inteiro N (1 ≤ N ≤ 100), indicando o número de navios.
 * Cada uma das próximas N linhas contém quatro inteiros:
 *     D, L, R e C com D ∈ {0, 1}, 1 ≤ L ≤ 5 e 1 ≤ R, C ≤ 10
 * descrevendo um navio.
 * Se D = 0 então o navio está alinhado horizontalmente, e ocupa as posições:
 *     (R, C) ... (R, C + L – 1)
 * Do contrário, o navio está alinhado verticalmente, e ocupa as posições
 *     (R, C) ... (R + L – 1, C)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define ROWS 10
#define COLUMNS 10
#define OCCUPIED_POS 1 // Marks an occupied position on the game board
#define EMPTY_POS 0 // Marks a free position on the game board


typedef struct {
    int direction;
    int length;
    int rowStart;
    int columnStart;
} Ship;


// --------------------------- BOARD OPERATIONS -----------------------------
void initBoard(int board[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = EMPTY_POS;
        }
    }
}

bool isPositionEmpty(int pos) {
    return pos == EMPTY_POS;
}


// ---------------------------- SHIP OPERATIONS -----------------------------
void validateShipInput(Ship ship) {
    if ((ship.direction < 0 || ship.direction > 1) ||   // Invalid direction
        (ship.length < 1 || ship.length > 5) ||         // Invalid length
        (ship.rowStart < 1 || ship.rowStart > 10) ||    // Invalid row start
        (ship.columnStart < 1 || ship.columnStart > 10) // Invalid column start
        ) {
        perror("Erro: dado de entrada invalido ou fora do limite!");
        exit(EXIT_FAILURE);
    }
}


void readShipFromFile(FILE *inputFile, Ship *ship) {
    fscanf(inputFile, "%d %d %d %d", &ship->direction,
                                     &ship->length,
                                     &ship->rowStart,
                                     &ship->columnStart);
    validateShipInput(*ship);
}

bool isShipValid(Ship ship, int gameBoard[ROWS][COLUMNS]) {
    // Ensure the ship doesn't get out of the board
    if (ship.columnStart + ship.length > COLUMNS ||
        ship.rowStart + ship.length > ROWS) {
        return false; // ship beyond the board limits
    }

    int currentRow = ship.rowStart;
    int currentCol = ship.columnStart;

    // Check if every position is available on the board
    for (int i = 0; i < ship.length; i++) {
        if (! isPositionEmpty(gameBoard[currentRow][currentCol]))
            return false;

        if (ship.direction == 0) // Ship is horizontally
            currentCol++;
        else // Ship is vertically
            currentRow++;
    }

    currentRow = ship.rowStart;
    currentCol = ship.columnStart;

    // Mark the ship position on the board
    for (int i = 0; i < ship.length; i++) {
        gameBoard[currentRow][currentCol] = OCCUPIED_POS;

        if (ship.direction == 0)
            currentCol++;
        else
            currentRow++;
    }
    return true;
}
// --------------------------------------------------------------------------


int main() {
    FILE *inputTests = fopen("./inputQ1.txt", "r");

    if (inputTests == NULL) {
        perror("Erro ao abrir o arquivo de testes!");
        exit(EXIT_FAILURE);
    }

    int numOfShips = 0;
    int gameBoard[ROWS][COLUMNS];
    initBoard(gameBoard);

    // Read the number of ships of current test case until the end of the file
    while (fscanf(inputTests, "%d", &numOfShips) == 1) {
        printf("Number of ships: %d\n", numOfShips);
        char result = 'Y';

        for (int i = 0; i < numOfShips; i++) {
            Ship ship = {0, 0, 0, 0};

            readShipFromFile(inputTests, &ship);

            printf("\n%d %d %d %d\n", ship.direction,
                                      ship.length,
                                      ship.rowStart,
                                      ship.columnStart);

            if (! isShipValid(ship, gameBoard))
                result = 'N';
        }
        printf("%c\n", result);
    }

    fclose(inputTests);
    return 0;
}