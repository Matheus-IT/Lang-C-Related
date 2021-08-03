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

bool isShipValid(Ship ship, int gameBoard[ROWS][COLUMNS]) {
    validateShipInput(ship);

    // Ensure the ship doesn't get out of the board
    if ((ship.direction == 0 && ship.columnStart-1 + ship.length > COLUMNS) ||
        (ship.direction == 1 && ship.rowStart-1 + ship.length > ROWS)) {
        return false; // ship beyond the board limits
    }

    int currentRow = ship.rowStart - 1;
    int currentCol = ship.columnStart - 1;

    // Check if every position is available on the board
    for (int i = 0; i < ship.length; i++) {
        if (! isPositionEmpty(gameBoard[currentRow][currentCol]))
            return false;

        if (ship.direction == 0) // Ship is horizontally
            currentCol++;
        else // Ship is vertically
            currentRow++;
    }

    currentRow = ship.rowStart - 1;
    currentCol = ship.columnStart - 1;

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