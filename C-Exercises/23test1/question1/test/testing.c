#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "./functions.h"


int main() {
    int gameBoard[ROWS][COLUMNS];
    initBoard(gameBoard);

    // --------------------- Testing ship horizontally -----------------------
    Ship ship = {0, 1, 10, 10};
    assert(isShipValid(ship, gameBoard) == true);
    printf(".");

    ship = (Ship) {0, 5, 1, 5};
    assert(isShipValid(ship, gameBoard) == true);
    printf(".");

    // --------------------- Testing ship vertically -------------------------
    ship = (Ship) {1, 1, 10, 10};
    assert(isShipValid(ship, gameBoard) == false);
    printf(".");

    ship = (Ship) {1, 5, 5, 1};
    assert(isShipValid(ship, gameBoard) == true);
    printf(".");

    // ------------------------ VALUES TO TESTS ------------------------------
    ship = (Ship) {0, 3, 2, 2};
    assert(isShipValid(ship, gameBoard) == true);
    printf(".");

    ship = (Ship) {1, 5, 2, 9};
    assert(isShipValid(ship, gameBoard) == true);
    printf(".");

    ship = (Ship) {1, 2, 3, 6};
    assert(isShipValid(ship, gameBoard) == true);
    printf(".");

    ship = (Ship) {1, 1, 4, 2};
    assert(isShipValid(ship, gameBoard) == true);
    printf(".");

    ship = (Ship) {0, 1, 6, 6};
    assert(isShipValid(ship, gameBoard) == true);
    printf(".");

    ship = (Ship) {0, 4, 8, 4};
    assert(isShipValid(ship, gameBoard) == true);
    printf(".");

    ship = (Ship) {0, 2, 10, 1};
    assert(isShipValid(ship, gameBoard) == true);
    printf(".");

    printf("\n");
    return 0;
}