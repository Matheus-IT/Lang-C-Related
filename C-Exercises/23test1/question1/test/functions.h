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