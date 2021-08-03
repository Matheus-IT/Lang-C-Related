#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "./functions.h"


int main() {
    int gameBoard[ROWS][COLUMNS];
    initBoard(gameBoard);

    Ship ship = {0, 0, 0, 0};
    assert(isShipValid(ship, gameBoard) == true);
    printf(".");

    ship = (Ship) {0, 10, 1, 1};
    assert(isShipValid(ship, gameBoard) == false);
    printf(".");

    ship = (Ship) {0, 1, 11, 11};
    assert(isShipValid(ship, gameBoard) == false);
    printf(".");

    ship = (Ship) {0, 10, 0, 0};
    assert(isShipValid(ship, gameBoard) == true);
    printf(".");

    ship = (Ship) {0, 1, 10, 10};
    assert(isShipValid(ship, gameBoard) == true);
    printf(".");

    printf("\n");
    return 0;
}